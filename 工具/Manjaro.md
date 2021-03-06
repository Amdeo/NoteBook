manjaro安装后配置

## 更新镜像排名

```
sudo pacman-mirrors -i -c China -m rank  
```

## 升级系统

```
sudo pacman -Syyu
```

## 安装archlinuxcn-keyring

```
sudo pacman -S archlinuxcn-keyring
sudo pacman -Syy//更新数据源
```

## 添加 archlinuxCN源

用 vim 编辑 /etc/pacman.conf --> 命令为：sudo vim /etc/pacman.conf

在文件底部添加以下几行：

```
[archlinuxcn]
SigLevel = Optional TrustedOnly
Server = https://mirrors.ustc.edu.cn/archlinuxcn/$arch
```

## 安装输入法（安装基于 fcitx 的搜狗输入法）

```
sudo pacman -S fcitx-im
sudo pacman -S fcitx-configtool
sudo pacman -S fcitx-sogoupinyin
```

添加输入法配置文件 (sudo vim ~/.xprofile)

```
export GTK_IM_MODULE=fcitx
export QT_IM_MODULE=fcitx
export XMODIFIERS="@im=fcitx"
```

## 安装yaourt、yay

```
sudo pacman -S yaourt
sudo pacman -S yay
```

## 安装WPS

```
sudo pacman -S wps-office
sudo pacman -S ttf-wps-fonts
```

解决无法输入中文问题：

`sudo vim /usr/bin/wps`，在第一行（`#!/bin/bash`）下面添加：

```
export GTK_IM_MODULE=fcitx
export QT_IM_MODULE=fcitx
export XMODIFIERS="@im=fcitx"
```

## 安装google-chrome浏览器

```
sudo pacman -S google-chrome
```

## 网易云音乐

```
sudo pacman -S netease-cloud-music
```

### markdown编辑器 typora

```
yaourt typora
```

### git客户端 gitkraken

```
yaourt GitKraken
```

### 图像编辑器 gimp

```
sudo pacman -S gimp
```

### PDF阅读器Foxit

```
yaourt foxit
```

### 截图工具深度截图

```
sudo pacman -S deepin-screenshot
```

配置系统快捷键

![深度截图_plasmashell_20190819234728](Manjaro.assets/深度截图_plasmashell_20190819234728.png)

![深度截图_plasmashell_20190819234748](Manjaro.assets/深度截图_plasmashell_20190819234748.png)

## 安装Anaconda

yaourt anaconda
source /opt/anaconda/bin/active root 

添加环境变量
    在〜/ .bashrc中添加

export PATH=/opt/anaconda/bin/:$PATH





# 问题

## majora Pacman正在使用

解决方法：/var/lib/pacman/db.lck

```
sudo rm -rf db.lck 
```

## 搜狗输入法异常！请删除.config/SogouPY 并重启

sogou-qimpanel

提示找不到libfcitx-qt.so，于是找到原因，安装fcitx-qt4就可以成功解决上述问题。

```
yaourt -S fcitx-qt4
```



## Manjaro更新后，中文显示为方框

```
sudo pacman -S wqy-microhei
```

