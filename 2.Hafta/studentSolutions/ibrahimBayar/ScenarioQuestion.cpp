// Yugi’nin kart destesini yönetiyorsun. 
// Kullanıcı olarak kart ekleyebilir, çıkarabilir, güncelleyebilir veya deste listesini görebilirsin. 
// Bir menü aracılığıyla bazı işlemleri yapıp, bunu konsolda göstermen gerekiyor. 

/// İşlem listesi şu şekildedir.
//  1 – Kart ekle
//	2 - Kart Sil (İsimle)
//	3 - Kart İsmini Güncelle (Eski isim → Yeni isim)
// 	4 - Deste Kartlarını Görüntüle
// 	5 - Kart Savaşı Başlat (Kart Seç → Kart Seç)
// 	6 - Savaş Sonuçlarını Gör (Sıralama)
// 	7 – Çıkış

/// Her kartın şu bilgileri olacak:
//  İsim
//  Atak (ATK)
//  Defans (DEF)
//  Sağlık (Max Sağlık ve Mevcut Sağlık) (HP)
//Kazanma Sayısı (başlangıç 0)

/// Savaş Kuralları
//	Kart1 → Kart2'ye saldırır → Hasar = Kart1.ATK - Kart2.DEF
//	Eğer Hasar > 0 → Kart2 HP -= Hasar
//	Eğer Hasar ≤ 0 → Kart2 hiç zarar görmez
//	Sonra Kart2 karşı saldırı yapar (aynı hesap)
//	Kartlardan biri HP ≤ 0 olursa kaybeder
//	Kazanan kartın kazanma sayısı +1 artar
//	Savaş tek tur veya sonuna kadar sürebilir


// Dark Magician (ATK:2500) saldırıyor Kuriboh (DEF:2000)→ Hasar = 2500 - 2000 = 500 → Kuriboh HP -= 500
// Kuriboh (ATK:300) saldırıyor Dark Magician (DEF:2100)→ Hasar = 300 - 2100 = -1800 → Hasar yok

// Yukarıda örnek bir savaş görülmektedir.

// Kazanan → HP > 0 kalan kart
// Kaybeden → HP ≤ 0 olan kart
// Kazanan kartın kazanma sayısı +1


// #####################################################################
// 
// Compile with:
// g++ ScenarioQuestion.cpp -o Test.exe -lgdi32 && Test.exe 
// 
// The card stats are not balanced. The game is not fun.
// 
// #####################################################################


#define UNICODE
#define _UNICODE

#include <windows.h>
#include <cwchar>


// control IDs
#define ID_BUTTON_PLAY  101
#define ID_BUTTON_QUIT  102
#define ID_BUTTON_ADD     201
#define ID_BUTTON_DELETE  202
#define ID_BUTTON_UPDATE  203
#define ID_BUTTON_BATTLE  204

static int selectedOpponentCard = -1;
static bool isBattleInProgress = false;
static int selectedPlayerCard = -1;
static bool isGameOver = false;
static int gameResult = 0; // 1: player wins, 2: opponent wins

const int creatureWidth = 33;
const int creatureHeight = 30;

const int creature[creatureHeight][creatureWidth] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    { 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1},
    { 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
    { 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
    { 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1},
    { 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1},
    { 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0},
    { 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0},
    { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    { 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
    { 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0},
    { 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0},
    { 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0},
    { 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0},
    { 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},


};

struct Card {
    const wchar_t* name;
    int atk;
    int def;
    int hpMax;
    int hpCurrent;
    int wins;
};

static Card deck[] = {
    { L"Dark Magician", 2500, 1800, 3000, 3000, 0 },
    { L"Kuriboh",        300, 1200, 1200, 1200, 0 },
    { L"Blue-Eyes",     3000, 1800, 4000, 4000, 0 }
};
static const int deckCount = sizeof(deck) / sizeof(deck[0]);
static bool showDeck = false;
static int hoveredCard = -1;

static Card opponentDeck[] = {
    { L"Stone Guardian", 2000, 2400, 2000, 2000, 0 }, // Tank with high ATK
    { L"Swift Fang",     2000, 1000, 1500, 1500, 0 }, // Attacker
    { L"Balanced Hero",  2500, 1200, 2000, 2000, 0 }  // Balanced
};
static const int opponentCount = sizeof(opponentDeck) / sizeof(opponentDeck[0]);
static int hoveredOpponent = -1;


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"WindowClass";
    WNDCLASS wc = { };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"Card Game",
        WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, 650, 500,
        nullptr,
        nullptr,
        hInstance,
        nullptr
    );
    if (!hwnd) return 0;

    ShowWindow(hwnd, nCmdShow);

    MSG msg = { };
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static HWND
        hPlay, hQuit,
        hAdd, hDelete, hUpdate, hBattle;

    switch (msg) {
    case WM_CREATE:
        hPlay = CreateWindowEx(
            0, L"BUTTON", L"Play",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            265, 180, 80, 30,
            hwnd, (HMENU)ID_BUTTON_PLAY,
            GetModuleHandle(nullptr), nullptr
        );
        hQuit = CreateWindowEx(
            0, L"BUTTON", L"Quit",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            265, 220, 80, 30,
            hwnd, (HMENU)ID_BUTTON_QUIT,
            GetModuleHandle(nullptr), nullptr
        );

        hAdd = CreateWindowEx(0, L"BUTTON", L"Kart Ekle",
            WS_TABSTOP | WS_CHILD | BS_PUSHBUTTON,
            95, 400, 100, 30, hwnd, (HMENU)ID_BUTTON_ADD,
            GetModuleHandle(NULL), NULL);
        ShowWindow(hAdd, SW_HIDE);

        hDelete = CreateWindowEx(0, L"BUTTON", L"Kart Sil",
            WS_TABSTOP | WS_CHILD | BS_PUSHBUTTON,
            205, 400, 100, 30, hwnd, (HMENU)ID_BUTTON_DELETE,
            GetModuleHandle(NULL), NULL);
        ShowWindow(hDelete, SW_HIDE);

        hUpdate = CreateWindowEx(0, L"BUTTON", L"Kart Güncelle",
            WS_TABSTOP | WS_CHILD | BS_PUSHBUTTON,
            315, 400, 100, 30, hwnd, (HMENU)ID_BUTTON_UPDATE,
            GetModuleHandle(NULL), NULL);
        ShowWindow(hUpdate, SW_HIDE);

        hBattle = CreateWindowEx(0, L"BUTTON", L"Savaşı Başlat",
            WS_TABSTOP | WS_CHILD | BS_PUSHBUTTON,
            425, 400, 120, 30, hwnd, (HMENU)ID_BUTTON_BATTLE,
            GetModuleHandle(NULL), NULL);
        ShowWindow(hBattle, SW_HIDE);

        return 0;

    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case ID_BUTTON_PLAY:
            showDeck = true;
            ShowWindow(hPlay, SW_HIDE);
            ShowWindow(hQuit, SW_HIDE);
            ShowWindow(hAdd, SW_SHOW);
            ShowWindow(hDelete, SW_SHOW);
            ShowWindow(hUpdate, SW_SHOW);
            ShowWindow(hBattle, SW_SHOW);
            InvalidateRect(hwnd, nullptr, TRUE);
            break;
        case ID_BUTTON_QUIT:
            PostQuitMessage(0);
            break;
        case ID_BUTTON_ADD:
            MessageBox(hwnd, L"Kart ekleme mantığı eklenmedi", L"Info", MB_OK);
            break;
        case ID_BUTTON_DELETE:
            MessageBox(hwnd, L"Kart Silme mantığı eklenmedi", L"Info", MB_OK);
            break;
        case ID_BUTTON_UPDATE:
            MessageBox(hwnd, L"Kart Güncelleme mantığı eklenmedi", L"Info", MB_OK);
            break;
        case ID_BUTTON_BATTLE:
            if (isGameOver) {
                for (int i = 0; i < deckCount; ++i) {
                    deck[i].hpCurrent = deck[i].hpMax;
                }
                for (int i = 0; i < opponentCount; ++i) {
                    opponentDeck[i].hpCurrent = opponentDeck[i].hpMax;
                }
                selectedPlayerCard = -1;
                selectedOpponentCard = -1;
                isGameOver = false;
                gameResult = 0;
                InvalidateRect(hwnd, NULL, TRUE);
            }
            if (!isBattleInProgress && !isGameOver) {
                isBattleInProgress = true;
                selectedOpponentCard = -1;
                SetTimer(hwnd, 1, 1000, NULL);
            }
            break;
        }
        return 0;

    case WM_TIMER:
        if (wParam == 1 && isBattleInProgress) {
            int idx, attempts = 0;
            do {
                idx = rand() % opponentCount;
            } while (opponentDeck[idx].hpCurrent <= 0 && ++attempts < 100);
            selectedOpponentCard = idx;
            KillTimer(hwnd, 1);
            InvalidateRect(hwnd, NULL, TRUE);
        }

        else if (wParam == 2 && isBattleInProgress && selectedPlayerCard != -1 && selectedOpponentCard != -1) {
            Card& player = deck[selectedPlayerCard];
            Card& enemy = opponentDeck[selectedOpponentCard];

            if (enemy.hpCurrent > 0) {
                int dmgToEnemy = player.atk - enemy.def;
                if (dmgToEnemy > 0) enemy.hpCurrent -= dmgToEnemy;
            }
            if (player.hpCurrent > 0) {
                int dmgToPlayer = enemy.atk - player.def;
                if (dmgToPlayer > 0) player.hpCurrent -= dmgToPlayer;
            }


            if (enemy.hpCurrent <= 0 && player.hpCurrent > 0)
                player.wins++;
            else if (player.hpCurrent <= 0 && enemy.hpCurrent > 0)
                enemy.wins++;

            selectedPlayerCard = -1;
            selectedOpponentCard = -1;

            bool playerAlive = false, enemyAlive = false;
            for (int i = 0; i < deckCount; ++i) {
                if (deck[i].hpCurrent > 0) {
                    playerAlive = true;
                    break;
                }
            }
            for (int i = 0; i < opponentCount; ++i) {
                if (opponentDeck[i].hpCurrent > 0) {
                    enemyAlive = true;
                    break;
                }
            }

            if (playerAlive && enemyAlive) {
                SetTimer(hwnd, 1, 1000, NULL);
            }
            else {
                isBattleInProgress = false;
                isGameOver = true;
                if (playerAlive)
                    gameResult = 1; // Player wins
                else if (enemyAlive)
                    gameResult = 2; // Opponent wins
                else
                    gameResult = 0; // Draw (optional)
            }

            KillTimer(hwnd, 2);
            InvalidateRect(hwnd, NULL, TRUE);
        }

    case WM_MOUSEMOVE:
        if (showDeck) {
            int mx = LOWORD(lParam), my = HIWORD(lParam);
            RECT cr; GetClientRect(hwnd, &cr);
            const int cardW = 80, cardH = 50, spacing = 10;

            int totalW = deckCount * cardW + (deckCount - 1) * spacing;
            int startX = (cr.right - totalW) / 2;
            int y = cr.bottom - cardH - 80;

            int newHover = -1;
            for (int i = 0; i < deckCount; ++i) {
                if (deck[i].hpCurrent <= 0) continue;
                int x = startX + i * (cardW + spacing);
                if (mx >= x && mx < x + cardW && my >= y && my < y + cardH) {
                    newHover = i;
                    break;
                }
            }

            if (newHover != hoveredCard) {
                RECT r;
                if (hoveredCard >= 0) {
                    int ox = startX + hoveredCard * (cardW + spacing);
                    SetRect(&r, ox, y, ox + cardW, y + cardH);
                    InvalidateRect(hwnd, &r, TRUE);
                }
                if (newHover >= 0) {
                    int nx = startX + newHover * (cardW + spacing);
                    SetRect(&r, nx, y, nx + cardW, y + cardH);
                    InvalidateRect(hwnd, &r, TRUE);
                }
                RECT infoRect = { 10, 10, 200, 100 };
                InvalidateRect(hwnd, &infoRect, TRUE);
                hoveredCard = newHover;
            }

            int oppTotalW = opponentCount * cardW + (opponentCount - 1) * spacing;
            int oppStartX = (cr.right - oppTotalW) / 2;
            int oppY = 20;

            int newHoverOpponent = -1;
            for (int i = 0; i < opponentCount; ++i) {
                if (opponentDeck[i].hpCurrent <= 0) continue;
                int x = oppStartX + i * (cardW + spacing);
                int yOffset = (i == selectedOpponentCard) ? 15 : 0;
                int cardY = oppY + yOffset;
                if (mx >= x && mx < x + cardW && my >= cardY && my < cardY + cardH) {
                    newHoverOpponent = i;
                    break;
                }
            }

            if (newHoverOpponent != hoveredOpponent) {
                RECT r;
                if (hoveredOpponent >= 0) {
                    int ox = oppStartX + hoveredOpponent * (cardW + spacing);
                    int yOffsetOld = (hoveredOpponent == selectedOpponentCard) ? 15 : 0;
                    SetRect(&r, ox, oppY + yOffsetOld, ox + cardW, oppY + yOffsetOld + cardH);
                    InvalidateRect(hwnd, &r, TRUE);
                }
                if (newHoverOpponent >= 0) {
                    int nx = oppStartX + newHoverOpponent * (cardW + spacing);
                    int yOffsetNew = (newHoverOpponent == selectedOpponentCard) ? 15 : 0;
                    SetRect(&r, nx, oppY + yOffsetNew, nx + cardW, oppY + yOffsetNew + cardH);
                    InvalidateRect(hwnd, &r, TRUE);
                }
                RECT infoRect = { cr.right - 160, 10, cr.right - 10, 100 };
                InvalidateRect(hwnd, &infoRect, TRUE);
                hoveredOpponent = newHoverOpponent;
            }
        }
        return 0;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        if(showDeck){
            RECT cr;
            GetClientRect(hwnd, &cr);
            int oppCardW = 80, oppCardH = 50, spacing = 10;
            int oppTotalW = opponentCount * oppCardW + (opponentCount - 1) * spacing;
            int oppStartX = (cr.right - oppTotalW) / 2;
            int oppY = 20;

            for (int i = 0; i < opponentCount; ++i) {
                int x = oppStartX + i * (oppCardW + spacing);
                int yOffset = (i == selectedOpponentCard) ? 15 : 0;
                int y = oppY + yOffset;

                COLORREF col = RGB(128, 0, 0);

                HPEN pen = CreatePen(PS_SOLID, 2, col);
                HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
                HPEN oldPen = (HPEN)SelectObject(hdc, pen);
                HBRUSH oldBr = (HBRUSH)SelectObject(hdc, brush);
                Rectangle(hdc, x, y, x + oppCardW, y + oppCardH);
                SelectObject(hdc, oldPen);
                SelectObject(hdc, oldBr);
                DeleteObject(pen);

                SetTextColor(hdc, col);
                SetBkMode(hdc, TRANSPARENT);
                RECT textR = { x + 4, y + 4, x + oppCardW - 4, y + oppCardH - 4 };
                DrawTextW(hdc, opponentDeck[i].name, -1, &textR, DT_WORDBREAK | DT_CENTER);

                if (opponentDeck[i].hpCurrent <= 0) {
                    HPEN p = CreatePen(PS_SOLID, 3, RGB(200, 0, 0));
                    HPEN old = (HPEN)SelectObject(hdc, p);
                    MoveToEx(hdc, x, y, NULL); LineTo(hdc, x + oppCardW, y + oppCardH);
                    MoveToEx(hdc, x + oppCardW, y, NULL); LineTo(hdc, x, y + oppCardH);
                    SelectObject(hdc, old); DeleteObject(p);
                }
            }
        }

        if (showDeck) {
            RECT cr; GetClientRect(hwnd, &cr);
            const int cardW = 80, cardH = 50, spacing = 10;
            int totalW = deckCount * cardW + (deckCount - 1) * spacing;
            int startX = (cr.right - totalW) / 2;
            int y = cr.bottom - cardH - 80;

            for (int i = 0; i < deckCount; ++i) {
                int x = startX + i * (cardW + spacing);

                COLORREF col = (i == hoveredCard)
                    ? RGB(0, 255, 0)
                    : RGB(0, 0, 0);

                HPEN pen = CreatePen(PS_SOLID, 2, col);
                HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
                HPEN oldPen = (HPEN)SelectObject(hdc, pen);
                HBRUSH oldBr = (HBRUSH)SelectObject(hdc, brush);
                Rectangle(hdc, x, y, x + cardW, y + cardH);
                SelectObject(hdc, oldPen);
                SelectObject(hdc, oldBr);
                DeleteObject(pen);

                SetTextColor(hdc, col);
                SetBkMode(hdc, TRANSPARENT);
                RECT textR = { x + 4, y + 4, x + cardW - 4, y + cardH - 4 };
                DrawTextW(hdc, deck[i].name, -1, &textR, DT_WORDBREAK | DT_CENTER);

                if (deck[i].hpCurrent <= 0) {
                    HPEN redPen = CreatePen(PS_SOLID, 3, RGB(200, 0, 0));
                    HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
                    MoveToEx(hdc, x, y, NULL);
                    LineTo(hdc, x + cardW, y + cardH);
                    MoveToEx(hdc, x + cardW, y, NULL);
                    LineTo(hdc, x, y + cardH);
                    SelectObject(hdc, oldPen);
                    DeleteObject(redPen);
                }
            }
        }

        if (hoveredCard >= 0) {
            RECT infoRect = { 10, 10, 150, 95 };
            HBRUSH infoBrush = CreateSolidBrush(RGB(240, 240, 240));
            FillRect(hdc, &infoRect, infoBrush);
            DeleteObject(infoBrush);

            HPEN pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
            HPEN oldPen = (HPEN)SelectObject(hdc, pen);
            MoveToEx(hdc, infoRect.left, infoRect.top, NULL);
            LineTo(hdc, infoRect.right, infoRect.top);
            LineTo(hdc, infoRect.right, infoRect.bottom);
            LineTo(hdc, infoRect.left, infoRect.bottom);
            LineTo(hdc, infoRect.left, infoRect.top);
            SelectObject(hdc, oldPen);
            DeleteObject(pen);

            const Card& card = deck[hoveredCard];
            wchar_t infoText[256];
            swprintf(infoText, 256,
                L"Name: %s\nATK: %d\nDEF: %d\nHP: %d / %d\nWins: %d",
                card.name, card.atk, card.def, card.hpCurrent, card.hpMax, card.wins);

            SetTextColor(hdc, RGB(0, 0, 0));
            SetBkMode(hdc, TRANSPARENT);
            DrawTextW(hdc, infoText, -1, &infoRect, DT_LEFT | DT_TOP);
        }

        if (hoveredOpponent >= 0) {
            RECT cr; GetClientRect(hwnd, &cr);
            RECT infoRect = { cr.right - 160, 10, cr.right - 10, 97 };
            HBRUSH infoBrush = CreateSolidBrush(RGB(255, 240, 240));
            FillRect(hdc, &infoRect, infoBrush);
            DeleteObject(infoBrush);

            HPEN pen = CreatePen(PS_SOLID, 1, RGB(128, 0, 0));
            HPEN oldPen = (HPEN)SelectObject(hdc, pen);
            MoveToEx(hdc, infoRect.left, infoRect.top, NULL);
            LineTo(hdc, infoRect.right, infoRect.top);
            LineTo(hdc, infoRect.right, infoRect.bottom);
            LineTo(hdc, infoRect.left, infoRect.bottom);
            LineTo(hdc, infoRect.left, infoRect.top);
            SelectObject(hdc, oldPen);
            DeleteObject(pen);

            const Card& card = opponentDeck[hoveredOpponent];
            wchar_t infoText[256];
            swprintf(infoText, 256,
                L"Name: %s\nATK: %d\nDEF: %d\nHP: %d / %d\nWins: %d",
                card.name, card.atk, card.def, card.hpCurrent, card.hpMax, card.wins);

            SetTextColor(hdc, RGB(128, 0, 0));
            SetBkMode(hdc, TRANSPARENT);
            DrawTextW(hdc, infoText, -1, &infoRect, DT_LEFT | DT_TOP);
        }

        if (showDeck) {
            int pixelSize = 5;
            int originX = 245, originY = 90;

            for (int y = 0; y < creatureHeight; ++y) {
                for (int x = 0; x < creatureWidth; ++x) {
                    if (creature[y][x] == 1) {
                        RECT r = {
                            originX + x * pixelSize,
                            originY + y * (pixelSize + 1),
                            originX + (x + 1) * pixelSize,
                            originY + (y + 1) * (pixelSize + 1)
                        };

                        HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0)); // green
                        FillRect(hdc, &r, brush);
                        DeleteObject(brush);
                    }
                }
            }
        }

        if (isGameOver) {
            RECT cr; GetClientRect(hwnd, &cr);
            const wchar_t* text = (gameResult == 1) ? L"Kazandın!" :
                (gameResult == 2) ? L"Kaybettin!" :
                L"Berabere!";

            int msgW = 320, msgH = 80;
            int centerX = (cr.left + cr.right) / 2;
            int centerY = (cr.top + cr.bottom) / 2;
            RECT msgBg = {
                centerX - msgW / 2,
                centerY - msgH / 2,
                centerX + msgW / 2,
                centerY + msgH / 2
            };

            HBRUSH bgBrush = CreateSolidBrush(RGB(255, 255, 180));
            FillRect(hdc, &msgBg, bgBrush);
            DeleteObject(bgBrush);

            HPEN borderPen = CreatePen(PS_SOLID, 3, RGB(180, 160, 0));
            HPEN oldPen = (HPEN)SelectObject(hdc, borderPen);
            MoveToEx(hdc, msgBg.left, msgBg.top, NULL);
            LineTo(hdc, msgBg.right, msgBg.top);
            LineTo(hdc, msgBg.right, msgBg.bottom);
            LineTo(hdc, msgBg.left, msgBg.bottom);
            LineTo(hdc, msgBg.left, msgBg.top);
            SelectObject(hdc, oldPen);
            DeleteObject(borderPen);

            SetBkMode(hdc, TRANSPARENT);
            SetTextColor(hdc, (gameResult == 1) ? RGB(0, 150, 0) : RGB(200, 0, 0));
            HFONT hFont = CreateFontW(36, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
                DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY,
                VARIABLE_PITCH, L"Segoe UI");
            HFONT oldFont = (HFONT)SelectObject(hdc, hFont);
            DrawTextW(hdc, text, -1, &msgBg, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            SelectObject(hdc, oldFont);
            DeleteObject(hFont);
        }

        EndPaint(hwnd, &ps);
        return 0;
    }

    case WM_LBUTTONDOWN: {
        if (isBattleInProgress && selectedOpponentCard >= 0 && selectedPlayerCard == -1) {
            int mx = LOWORD(lParam), my = HIWORD(lParam);
            RECT cr; GetClientRect(hwnd, &cr);
            const int cardW = 80, cardH = 50, spacing = 10;
            int totalW = deckCount * cardW + (deckCount - 1) * spacing;
            int startX = (cr.right - totalW) / 2;
            int y = cr.bottom - cardH - 80;

            for (int i = 0; i < deckCount; ++i) {
                int x = startX + i * (cardW + spacing);
                if (mx >= x && mx < x + cardW && my >= y && my < y + cardH) {
                    if (deck[i].hpCurrent > 0) {
                        selectedPlayerCard = i;
                        SetTimer(hwnd, 2, 1000, NULL); // 1 second delay for result
                    }
                    break;
                }
            }
        }
        return 0;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}
