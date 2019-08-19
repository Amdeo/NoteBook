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

## Manjaro更新后，中文显示为方框

```
sudo pacman -S wqy-microhei
```

## 安装yaourt、yay

```
sudo pacman -S yaourt
sudo pacman -S yay
```

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

