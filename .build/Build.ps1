$InstallerDir = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer"
$VsWhere = "$InstallerDir\vswhere.exe"
$MSBuildPath = (&"$VsWhere" -latest -products * -find "\MSBuild\Current\Bin\MSBuild.exe").Trim()
$Root = (Get-Item -Path $PSScriptRoot).Parent.FullName
$Now = [System.DateTime]::UtcNow
$CurrentVersionString = $Now.ToString("yyyy.MM.dd.HHmm")

&"$MSBuildPath" "$Root\TightVncPassword" -p:Configuration=Release -p:Platform=Win32 -p:Version=$CurrentVersionString -p:FileVersion=$CurrentVersionString
&"$MSBuildPath" "$Root\TightVncPassword" -p:Configuration=Release -p:Platform=x64 -p:Version=$CurrentVersionString -p:FileVersion=$CurrentVersionString

New-Item -Path "$Root\bin\" -ItemType Directory -Force
Copy-Item -Path "$Root\TightVncPassword\x64\Release\TightVncPassword.exe" -Destination "$Root\bin\TightVncPassword_x64.exe" -Force
Copy-Item -Path "$Root\TightVncPassword\Release\TightVncPassword.exe" -Destination "$Root\bin\TightVncPassword_x86.exe" -Force