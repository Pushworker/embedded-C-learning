#  Git 与 GitHub 实战速查手册（WSL/Ubuntu 版）

## 一、 初始配置（一辈子只需做一次）

如果你换了一台新电脑，或者重装了系统，第一件事就是配置身份和网络。

**1. 配置全局账号**

bash

```
git config --global user.name "Pushworker"           # 你的 GitHub 用户名
git config --global user.email "m18909152473@163.com" # 你的邮箱
```



**2. 生成 SSH 密钥（免密登录核心）**

bash

```
ssh-keygen -t rsa -b 4096 -C "你的邮箱"
# 连续按 3 次回车（一路默认，不设密码，存放在 ~/.ssh/id_rsa）
```



**3. 添加公钥到 GitHub**

bash

```
cat ~/.ssh/id_rsa.pub
# 复制屏幕上打印出的全部内容（以 ssh-rsa 开头）
```



去 GitHub 网页 -> 右上角头像 -> Settings -> SSH and GPG keys -> New SSH key -> 粘贴 -> Add SSH key。

**4. 绕过网络封锁（国内必备神技）**
如果你连不上 GitHub 报错 22 端口，必须配置 443 端口代理：

bash

```
echo "Host github.com" >> ~/.ssh/config
echo "  Hostname ssh.github.com" >> ~/.ssh/config
echo "  Port 443" >> ~/.ssh/config
echo "  User git" >> ~/.ssh/config
# 验证是否成功：出现 Hi Pushworker! 即可。
ssh -T git@github.com
```



------

## 二、 第一次将代码推送到 GitHub（建仓流程）

当你写好了一个项目，想把它传到 GitHub 上：

**1. 在 GitHub 网页上**：新建一个空仓库（**绝对不要**勾选 README、.gitignore 等）。
**2. 在终端进入项目目录，敲以下命令**：

bash

```
git init                                  # 初始化本地仓库
git add .                                 # 把所有文件加入暂存区
git commit -m "feat: 初始化项目"           # 提交到本地仓库
git branch -M main                        # 强制把主分支命名为 main
git remote add origin git@github.com:Pushworker/embedded-C-learning.git # 关联远程仓库
git push -u origin main                   # 推送到云端
```



------

## 三、 日常开发工作流（每天 90% 的时间都在用的“四连击”）

以后每天写代码，都是这 4 个步骤，千万别弄混：

**1. 开始写代码前（同步云端）**

bash

```
git pull origin main
# 确保本地和云端一致，避免冲突
```



**2. 写完代码后（本地提交）**

bash

```
git status          # 看看自己改了哪些文件（红色为未提交，绿色为已提交）
git add .           # 把所有改动放进“购物车”
git commit -m "feat: 新增环形缓冲区实现"  # 给这次改动打标签
```



**3. 上传到云端**

bash

```
git push origin main
```



------

## 四、 多台电脑/多人协作（克隆与拉取）

**1. 换了一台新电脑，怎么拿到代码？**

bash

```
git clone git@github.com:Pushworker/embedded-C-learning.git
# 注意：SSH 方式需要新电脑也配置好第 1 步中的 SSH 密钥。
```



**2. 别人电脑上更新了代码，你怎么同步？**
在你自己的电脑上，进入项目目录，敲：

bash

```
git pull origin main
```



------

## 五、 必备避坑指南（血泪总结）

1. **密码不是登录密码**：如果在 HTTPS 模式下推代码，密码要填 **PAT（个人访问令牌）**，不是登录密码。用 SSH 模式则不需要密码。
2. **`.gitignore` 是护身符**：编译产生的 `.o` 文件、可执行文件（`my_app`），甚至 `.vscode/` 文件夹，绝对不能传上云端。一定要写在 `.gitignore` 文件里。
3. **推之前必拉，拉之后再推**：防止本地和云端历史不一致导致 `Merge conflict`（合并冲突），新手遇到冲突极其痛苦。
4. **私钥绝不外传**：`~/.ssh/id_rsa` 是你的万能钥匙，绝对不能拷到别人电脑上。换电脑要重新生成一对新密钥。

------

### 🎯 记住这几个名词，以后再也不会懵：

- `origin`：远程仓库的默认名字。
- `main`：主分支的名字。
- `add`：把文件放进购物车。
- `commit`：结账，并打上小票。
- `push`：把小票和商品发到云端。
- `pull`：从云端把最新的东西拿回本地。

## 六 本地拉取GitHub文件如何跑通

你问到了一个新手的“经典痛点”：**我把一堆代码拉下来了，但我双击也运行不了啊，那怎么让它跑起来呢？**

别慌，这完全是因为从 GitHub 拉下来的是**“源代码（食材）”**，而不是**“可执行文件（做好的菜）”**。你要想吃上菜，得在本地重新“炒”一遍。

这就是为什么你的项目里有一个 `Makefile` 的原因！我来告诉你怎么用刚才拉下来的文件夹跑通全部代码：

### 🍳 核心概念：GitHub 上只有“食谱”，没有“菜”

因为你在配置 `.gitignore` 时，把 `.o` 和 `my_app` 等编译好的文件过滤掉了。这是极其正确的做法！因为：

- 我电脑（x86）编译好的程序，在别人的 Mac 或者 ARM 板子上跑不了。
- 每个人拉取代码后，**必须在自己的电脑上重新编译一次**。

### 🚀 实际操作：拉取后如何运行？

假设你在别人的电脑上 `git clone` 或者 `git pull` 了你的代码，终端进入了那个文件夹（比如 `embedded-C-learning`）。

**第一步：确认电脑上有“厨具”**
别人电脑上也需要有 `gcc` 和 `make`。如果没有，敲：

bash

```
sudo apt update
sudo apt install build-essential -y
```



**第二步：用 Makefile 一键“炒菜”**
只需要敲一个命令，神奇的 `Makefile` 就会自动去调编译器，把所有的 `.c` 文件编译好，并链接成最终程序：

bash

```
make
```



*(这时你会看到终端输出 `gcc -Wall -g -c main.c ...` 之类的信息，它在一口气编译所有文件！)*

**第三步：运行“成品”**
`make` 执行成功后，会生成一个可执行文件（你在 Makefile 里定义的名字是 `my_app`）。敲：

bash

```
./my_app
```



你就能看到程序的运行结果了！

**第四步：清理现场（可选）**
如果你想把编译生成的一堆 `.o` 临时文件删掉，保持文件夹干净，敲：

bash

```
make clean
```



所有 `.o` 文件和可执行文件瞬间消失，文件夹又变回了纯粹的源代码，随时可以重新 `make`。

------

### 💡 进阶：别人电脑上多了一个文件怎么办？

如果你在另一台电脑上拉取了代码，发现它多了一个 `README.md`，或者多了一个 `ring_buffer.c`。
这**完全不影响** `make`。
因为 `Makefile` 里的 `SRCS = main.c uart.c ...` 会自动识别要编译哪些文件。只要你没漏掉新文件的配置，它就会自动把新文件一并编译进去。

# Makeflie的使用

