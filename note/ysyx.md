[toc]

---
# 学习笔记
Keep It Simple, Stupid
笔记只会记下笔者认为必要的东西，仅供参考

[系统设计黄金法则：简单之美](https://blog.sciencenet.cn/blog-414166-562616.html)
[提问的智慧](https://github.com/ryanhanwu/How-To-Ask-Questions-The-Smart-Way/blob/main/README-zh_CN.md#%E7%AC%AC%E4%BA%8C%E6%AD%A5%E4%BD%BF%E7%94%A8%E9%A1%B9%E7%9B%AE%E9%82%AE%E4%BB%B6%E5%88%97%E8%A1%A8)和[别像弱智一样提问](https://github.com/tangx/Stop-Ask-Questions-The-Stupid-Ways/tree/master)

1. 简单，简单，先跑起来再说。
2. 精细化求助范围（对应社区）https://stackexchange.com/sites
3. 问题明确环境和差异，精简但要筛选出必要的可供推测的条件
4. 去情绪化，保持礼貌,  多多感谢
5. 目标+（环境）+差异
> 我正在尝试`···`，已知`···`，但是`···`

>请问一个关于 `···` 的问题。
我想要达到 `···` 效果，但是我这样做出现了 `···` 的问题。
报错日志是 `···` 的。（要 学会 画关键字）
我尝试过 `···` 方法来解决。
我尝试搜索过了 `···` 关键字，在里面找到了 这些 `URL` 的回答，尝试了还是没有解决问题。
我用的是 `···` 操作系统，版本号是多少。
我用的是 `···` 软件，版本号是多少。
谢谢

---
# 工具使用

## git使用

- 添加多个ssh密匙时，在.ssh文件夹中应配置config文件用于配置私匙对应的服务器。

    ```
    # gitlab
    Host gitlab.ylwnl.com  　
    HostName gitlab.xxx.com 　　
    PreferredAuthentications publickey  
    IdentityFile ~/.ssh/gitlab_id_rsa 

    # github
    Host github.com
    吧                                                                                     
    HostName github.com
    PreferredAuthentications publickey
    IdentityFile ~/.ssh/github_id_rsa

    # gitee
    Host gitee.com
    HostName gitee.com
    PreferredAuthentications publickey
    IdentityFile ~/.ssh/gitee_id_rsa
    ```
- 常用指令
    ```
    操作:   git init    git clone
            git add     git commit -m "xxx"     git push    
            git checkout (-b xxx)（创造并切换到xxx分支）
            git merge --no-f xxx（无论能否都提交到仓库）
            git reset --hard (xxx)（时间点的哈希值）
            git remote add      git push\pull
            git push --set-upstream （添加当前分支内容到远程仓库）
    ```

    ```
    状态：  git status  git log (--pretty==short简短信息) (xxx相关文件日志)
            git branch (xxx)（创造xxx分支）
            git log --graph
            git reflog（log为当前状态为终点，reflog为仓库操作日志）
    ```
- 在Github上查看分支差别（使用URL）
  > 两个分支比较        https://github.com/Pinksheepa/ysyx-2024 `/main...branch-A`
  > 七天前比较          https://github.com/Pinksheepa/ysyx-2024 `/main{@7.day.ago}...main`
  > 具体某一日期        https://github.com/Pinksheepa/ysyx-2024 `/main{@2024-12-12}...main`

## vscode 

- anaconda管理的虚拟环境要激活使用
  ```
  conda activate xxx(环境名或者绝对路径)
  
  conda env list(查看当前所处环境)
  ```



## Linux基础学习

### VIM操作

- 文字移动 `hjkl`  `w` `e` `b`   (`%`符号移动) `o`
- 修改 `i` `a` `A` `d` `r` `c`  `:(%)s/.../.../g`
  > `d + w // + $ // + e // + dd`
  > `y` `p`
- 数字用于重复次数      `d2w` `2w` `0`
- 撤销 `u` ctrl+r 恢复
- `p` 将删除暂存的内容插入
- 页面移动 ctrl+G `gg` `G` `...G` 
- 查找 `/...` `n` `N`
- 退出和保存 `:w ...` `:q!` 
- 运行外部指令 `:!` 
- 文本选择 `v`
- 文本融合 `:r`

