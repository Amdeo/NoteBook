## 查看当前环境shell

```shell
echo $SHELL
```

## 查看系统自带那些shell

```
cat /etc/shells
```

## 安装zsh

```
yum -y instal zsh #centos 安装zsh

pacman -S zsh #arch 安装zsh
```

## 将zsh设置为默认shell

```
chsh -s /bin/zsh
```

## 安装oh-my-zsh

自动安装

```
wget https://github.com/robbyrussell/oh-my-zsh/raw/master/tools/install.sh -O - | sh
```

zsh主题

```
# ls ~/.oh-my-zsh/themes
```

## 插件

### zsh-syntax-highlighting

```
git clone https://github.com/zsh-users/zsh-syntax-highlighting.git
echo "source ${(q-)PWD}/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh" >> ${ZDOTDIR:-$HOME}/.zshrc
```

```
source ./zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
```

#### zsh-autosuggestions

```
git clone https://github.com/zsh-users/zsh-autosuggestions ~/.zsh/zsh-autosuggestions
```

Add the following to your .zshrc:

```
source ~/.zsh/zsh-autosuggestions/zsh-autosuggestions.zsh
```

