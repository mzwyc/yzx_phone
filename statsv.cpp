#define _CRT_SECURE_NO_WARNINGS
#include "statsv.h"

//bool ipr(const WCHAR* processName) {
//    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
//    if (hSnapshot == INVALID_HANDLE_VALUE) {
//        std::wcerr << L"Failed to create snapshot!" << std::endl;
//        return false;
//    }
//
//    PROCESSENTRY32W pe32;
//    pe32.dwSize = sizeof(PROCESSENTRY32W);
//
//    if (!Process32FirstW(hSnapshot, &pe32)) {
//        std::wcerr << L"Failed to get first process!" << std::endl;
//        CloseHandle(hSnapshot);
//        return false;
//    }
//
//    do {
//        if (std::wcscmp(pe32.szExeFile, processName) == 0) {
//            CloseHandle(hSnapshot);
//            return true;
//        }
//    } while (Process32NextW(hSnapshot, &pe32));
//
//    CloseHandle(hSnapshot);
//    return false;
//}

bool sp(bool ushvmm[1010], std::string usrnm[1010], int usrpsd[1010]) {
    // ��ȡ��ǰʱ���  
    long long i = 0;
    while (true) {
        auto now = std::chrono::system_clock::now();

        // ת��Ϊtime_t���Ա���C�Ŀ⺯������  
        std::time_t now_c = std::chrono::system_clock::to_time_t(now - std::chrono::hours(24));

        // ת��Ϊ����ʱ��  
        std::tm* local_time = std::localtime(&now_c);

        // ��ȡʱ����  
        int hour = local_time->tm_hour;
        int minute = local_time->tm_min;
        int second = local_time->tm_sec;
        if (_kbhit() && _getch() == 'q') break;
        Sleep(1000);
        system("cls");
        printf("********yzxp********\n");
        printf("*      %02d", hour);
        printf("%c", (i%2ll==0?':':' '));
        printf("%02d       *\n",minute);
        printf("*   ����Q������    *\n");
        printf("*                  *\n");
        printf("*                  *\n");
        printf("*                  *\n");
        printf("*                  *\n");
        printf("*                  *\n");
        printf("*                  *\n");
        printf("*                  *\n");
        printf("*                  *\n");
        printf("*                  *\n");
        printf("********************\n");
        i++;
        i %= 2;
    }
    //printf("����������û����:->");
    //scanf("%lld", &i);
    printf("��ã�%s", usrnm[1]);
    if (!ushvmm[1]) {
        return true;
    }
}

bool zc(int vle)
{
    if (vle == 1) return true;
    printf("Erroro:File opened is Falid");
    return false;
}

std::string hmpgpl[maxy] = {
    "********yzxp********",
    "*                  *",
    "*                  *",
    "* ����        �ļ� *",
    "*                  *",
    "*                  *",
    "* ���±�      ��Ƶ *",
    "*                  *",
    "*                  *",
    "* ���        �豸 *",
    "*                  *",
    "*       1/1        *",
    "*                  *",
    "*                  *",
    "********************"
};

std::string hm_chd[maxy] = {
    "********yzxp********",
    "*                  *",
    "*******      *******",
    "**����*      *�ļ�**",
    "*******      *******",
    "*********    *******",
    "**���±�*    *��Ƶ**",
    "*********    *******",
    "*******      *******",
    "**���*      *�豸**",
    "*******      *******",
    "*       1/1        *",
    "*                  *",
    "*                  *",
    "********************"
};

void home(int tx, int ty)
{
    int page = 1;//ҳ��
    //int tx = 1;//��ǰ��4/1
    //int ty = 1;//��ǰ��2/1
    int txl[6] = { 0, 3, 6, 9, 12};
    int tyl[maxy][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 7, 20},
        {0, 5, 15},
        {0, 6, 20},
        {0, 8, 19},
        {0, 5, 14},
        {0, 8, 19},
        {0, 6, 19},
        {0, 5, 16},
        {0, 6, 19},
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    system("cls");
    for (int i = 0; i < maxy; i++) {
        for (int j = 0; j < maxx; j++) {
            if (i == 1 || i == maxy) printf("*");
            else {
                if ((i > txl[tx-1]+1 && i <= txl[tx]+1) && (j <= tyl[i][ty] && j > tyl[i][ty - 1])) {
                    std::cout << hm_chd[i][j];
                }
                else {
                    std::cout << hmpgpl[i][j];
                }
            }
        }
        printf("\n");
    }
    if (_kbhit()) {
        int ch = _getch();
        if (ch == 0xE0) { // �ж��Ƿ�Ϊ��չ��
            ch = _getch(); // ��ȡ��չ����ֵ
            switch (ch) {
            case 72: home((tx - 1 > 0 ? tx - 1 : tx), ty); break; // 0x48
            case 80: home((tx + 1 < 5 ? tx + 1 : tx), ty); break; // 0x50
            case 75: home(tx, (ty - 1 > 0 ? ty - 1 : ty)); break; // 0x4B
            case 77: home(tx, (ty + 1 < 3 ? ty + 1 : ty)); break; // 0x4D
            }
        }
        else if (ch == 13 || ch == 10) {
            if (ty == 1) {
                switch (tx) {
                case 1:
                    setting();
                    return;
                case 2:
                    notepad();
                    return;
                case 3:
                    IDE();
                    return;
                }
            }
            else {
                switch (tx) {
                case 1:
                    fhp();
                    return;
                case 2:
                    vedeo();
                    return;
                case 3:
                    times();
                    return;
                }
            }
        }
    }
    Sleep(1000);
    home(tx, ty);
}

void setting()
{

}

void fhp()
{
}

void notepad()
{
}

void vedeo()
{
}

void times()
{
}

void IDE()
{
}
