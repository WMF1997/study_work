# Study_Work

这个是我看和找工作相关的 C/C++ 代码的. 

也许费的时间真的真的真的会有点长... 尽量吧.

@wmf1997
2021.4.8 

有的时候可能会忘记将已有的可执行文件清空. 
所以再这里记录一下, 这种情况不得不删掉之前所有的commit... 

```bash
# Checkout. (To a new branch)
git checkout --orphan latest_branch  # ${YOUR_BRANCH}

# Add all the files. (In the new branch)
git add -A

# Commit. (In the new branch)
git commit -am "helloworld"  # Any message you like in "", for example, "hey,you"

# Delete the Branch (Delete the "Wrong" Branch, (Inside your new branch, for example, main/master branch))
git branch -D main

# Rename the current branch, to main/master branch
git branch -m main

# Force Update 
git push -f origin main
```