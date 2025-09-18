# 在 Arch Linux 上安装 Matlab

我的电脑使用 KDE+Wayland

先参考 [ArchWiki](https://wiki.archlinux.org/title/MATLAB) , 其表明 Matlab 官方安装包不支持 Wayland

果然，[官方下载页面](https://ww2.mathworks.cn/downloads/) 提供的 zip 文件和学校提供的 iso 文件中的 `install` 都无法运行

尝试使用 `mpm` , 成功安装 `R2025a`
```bash
curl https://www.mathworks.com/mpm/glnxa64/mpm
chmod +x ./mpm
./mpm install --release=R2025a --destination=/home/lyy/matlab MATLAB Simulink
```

但是, Matlab 启动后一段时间会自动崩溃

[BBS](https://bbs.archlinux.org/viewtopic.php?id=305604#p2245074) 上有用户提出 `R2024b` 不会产生该问题, 于是切换到该版本

此时 Matlab 本体暂时无法成功启动, 但可以在出现的窗口中登录 MathWorks 账号

成功登录后，再启动 Matlab, log 显示 `error 5201`

参考 [ArchWiki](https://wiki.archlinux.org/title/MATLAB#MATLAB_fails_to_run_with_%22Unable_to_access_services_required_to_run_MATLAB_(error_5201)%22_on_startup) , 重装 `MathWorks Service Host` 即可

```bash
wget https://www.mathworks.com/MathWorksServiceHost/glnxa64/ReinstallMathWorksServiceHost
chmod +x ReinstallMathWorksServiceHost
./ReinstallMathWorksServiceHost
```

此时 Matlab 仍然会崩溃, [BBS](https://bbs.archlinux.org/viewtopic.php?id=306939#p2251599) 上用户指出问题可能由 `gnutls-3.8.10` 的兼容性问题引起

将其降级至 `3.8.9` 当然可行, 但更好的做法是直接将 `gnutls-3.8.9` 的共享对象文件放到 Matlab 安装目录中

```bash
wget https://archive.archlinux.org/packages/g/gnutls/gnutls-3.8.9-1-x86_64.pkg.tar.zst
mkdir -p /tmp/gnutls
tar -xvf gnutls-3.8.9-1-x86_64.pkg.tar.zst -C /tmp/gnutls
cp -r /tmp/gnutls/usr/lib/* /home/lyy/matlab/bin/glnxa64/
```

终于，Matlab 可以正常运行了

参考 [BBS](https://bbs.archlinux.org/viewtopic.php?id=300079#p2201246), 若 `Simulink` 无法打开，安装 `libxcrypt-compat` 即可
