#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <variant>
#include <vector>
#include <thread>
#include <cstdio>
#include <Windows.h>
#include <tchar.h>


#define _CRT_NONSTDC_NO_WARNINGS

using namespace std;

void create_process(const char* cmdline)
{
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    LPSTR commline = _strdup(cmdline);
    if (CreateProcessA(NULL, commline, NULL, NULL, FALSE, DETACHED_PROCESS, NULL, NULL, &si, &pi)) {
        printf("CreateProcess failed (%d).\n", GetLastError());
        return;
    }
    // Wait until child process exits.
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles. 
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

bool create_write_file(const char* filename, const char* data)
{
    int len = strlen(data);
    FILE* f = fopen(filename, "w");
    if (!f) {
        printf("File open %s failed\n", filename);
        return false;
    }
    size_t written = fwrite((void*)data, sizeof(*data), len + 1, f);
    if (written != len + 1) {
        printf("Write failed! %llu != %d\n", written, len + 1);
        return false;
    }
    //fflush(f);
    int closed = fclose(f);
    if (closed) {
        printf("File close failed: %s, returned: %d\n", filename, closed);
    }
    // now read it using another process
    bool read_well = false;
    //auto reader = [filename, data, len, &read_well]() {
    //    FILE* f = fopen(filename, "r");
    //    if (!f) {
    //        printf("File open %s failed\n", filename);
    //        return false;
    //    }
    //    char* buff = (char*)malloc(len + 1);
    //    if (!buff) { printf("malloc failed\n"); return false; }
    //    memset(buff, 'a', len + 1);
    //    size_t read = fread(buff, sizeof(*data), len + 1, f);
    //    if (read != len + 1) {
    //        printf("Read failed! %llu != %d\n", read, len + 1);
    //        free(buff);
    //        return false;
    //    }
    //    if (strcmp(buff, data) != 0) {
    //        printf("Read something different!:%s!=%s\n", buff, data);
    //    }
    //    else {
    //        read_well = true;
    //    }
    //    free(buff);
    //    int closed = fclose(f);
    //    if (closed) {
    //        printf("File close failed: %s, returned: %d\n", filename, closed);
    //        return false;
    //    }
    //};
    //thread t1(reader);
    //t1.join();



    return read_well;
}


void run(const char* filename)
{
    srand(time(NULL));
    size_t datalen = (0x1 << 16) + 10;
    char* data = (char*)malloc(datalen);
    if (!data) {
        printf("Couod jn0ot allocate enoguh mem\n");
        return;
    }
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < datalen - 1; j++) {
            data[j] = 'a' + (rand() % ('z' - 'a'));
        }
        data[datalen - 1] = '\0';
        bool res = create_write_file(filename, data);
        if (!res) {
            printf("failed!\n");
        }
    }
    free(data);
}

const char* names[8] = {
    "hello1.txt",
    "hello2.txt",
    "hello3.txt",
    "hello4.txt",
    "hello5.txt",
    "hello6.txt",
    "hello7.txt",
    "hello8.txt",
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    // write code here
    //const int num_threads = 8;
    //thread threads[num_threads];
    //for (int i = 0; i < num_threads; i++) {
    //    threads[i] = thread(run, names[i]);
    //}
    //for (int i = 0; i < num_threads; i++) {
    //    if(threads[i].joinable())
    //        threads[i].join();
    //}

    const char* appname = "C:\\Windows\\notepad.exe";
    create_process(appname);
    create_process(appname);
    //run("muska.txt");

    return 0;
}