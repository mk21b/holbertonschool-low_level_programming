# ~/.bashrc: executed by bash(1) for non-login shells.
# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
# for examples

# If not running interactively, don't do anything
[ -z "$PS1" ] && return

# don't put duplicate lines in the history. See bash(1) for more options
# ... or force ignoredups and ignorespace
HISTCONTROL=ignoredups:ignorespace

# append to the history file, don't overwrite it
shopt -s histappend

# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
HISTSIZE=1000
HISTFILESIZE=2000

# check the window size after each command and, if necessary,
# update the values of LINES and COLUMNS.
shopt -s checkwinsize

# make less more friendly for non-text input files, see lesspipe(1)
[ -x /usr/bin/lesspipe ] && eval "$(SHELL=/bin/sh lesspipe)"

# set variable identifying the chroot you work in (used in the prompt below)
if [ -z "$debian_chroot" ] && [ -r /etc/debian_chroot ]; then
    debian_chroot=$(cat /etc/debian_chroot)
fi

# set a fancy prompt (non-color, unless we know we "want" color)
case "$TERM" in
    xterm-color) color_prompt=yes;;
esac

# uncomment for a colored prompt, if the terminal has the capability; turned
# off by default to not distract the user: the focus in a terminal window
# should be on the output of commands, not on the prompt
#force_color_prompt=yes

if [ -n "$force_color_prompt" ]; then
    if [ -x /usr/bin/tput ] && tput setaf 1 >&/dev/null; then
	# We have color support; assume it's compliant with Ecma-48
	# (ISO/IEC-6429). (Lack of such support is extremely rare, and such
	# a case would tend to support setf rather than setaf.)
	color_prompt=yes
    else
	color_prompt=
    fi
fi

if [ "$color_prompt" = yes ]; then
    PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '
else
    PS1='${debian_chroot:+($debian_chroot)}\u@\h:\w\$ '
fi
unset color_prompt force_color_prompt

# If this is an xterm set the title to user@host:dir
case "$TERM" in
xterm*|rxvt*)
    PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h: \w\a\]$PS1"
    ;;
*)
    ;;
esac

# enable color support of ls and also add handy aliases
if [ -x /usr/bin/dircolors ]; then
    test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
    alias ls='ls --color=auto'
    #alias dir='dir --color=auto'
    #alias vdir='vdir --color=auto'

    alias grep='grep --color=auto'
    alias fgrep='fgrep --color=auto'
    alias egrep='egrep --color=auto'
fi

# some more ls aliases
alias ll='ls -alF'
alias la='ls -A'
alias l='ls -CF'

# Alias definitions.
# You may want to put all your additions into a separate file like
# ~/.bash_aliases, instead of adding them here directly.
# See /usr/share/doc/bash-doc/examples in the bash-doc package.

if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi

# enable programmable completion features (you don't need to enable
# this, if it's already enabled in /etc/bash.bashrc and /etc/profile
# sources /etc/bash.bashrc).
#if [ -f /etc/bash_completion ] && ! shopt -oq posix; then
#    . /etc/bash_completion
#fi
export PROMPT_COMMAND="history -a"

source $HOME/.bash_aliases;

if [[ ! -f ~/.age ]]; then
    touch $HOME/.age;
fi
agefile=$HOME/.age;

###Colors
CYAN="\[\e[38;2;25;249;216m\]";
GREEN="\[\e[38;2;93;213;3m\]";
YELLOW="\[\e[38;2;211;173;3m\]";
BLUE="\[\e[38;2;0;172;253m\]";
AE="\[\e[0m\]";
MPC=$CYAN;

###VCS_PROMPT

VCS_F_BEHIND(){
    VCS_BEHIND=$(git rev-list --count HEAD..@{u});
    VCS_S_BEHIND="⇣"
    if [[ "$VCS_BEHIND" > 0 ]]; then
	VCS_P_BEHIND="${VCS_S_BEHIND}${VCS_BEHIND}";
	echo -n " " | cat - <(echo -n "${VCS_P_BEHIND}" | xargs) | tr -d '\n';
    fi
}

VCS_F_AHEAD(){
    VCS_AHEAD=$(git rev-list --count @{u}..HEAD);
    VCS_S_AHEAD="⇡"
    if [[ "$VCS_AHEAD" > 0 ]]; then
	VCS_P_AHEAD="${VCS_S_AHEAD}${VCS_AHEAD}";
	echo -n " " | cat - <(echo -n "${VCS_P_AHEAD}" | xargs) | tr -d '\n';
    fi
}

VCS_F_UNCOMMITED(){
    VCS_UNCOMMITED=$(git status --porcelain |sed 's/^ //'| grep ^"A" | wc -l);
    VCS_S_UNCOMMITED="+"
    if [[ "$VCS_UNCOMMITED" > 0 ]]; then
	VCS_P_UNCOMMITED="${VCS_S_UNCOMMITED}${VCS_UNCOMMITED}";
	echo -n " " | cat - <(echo -n "${VCS_P_UNCOMMITED}" | xargs) | tr -d '\n';
    fi
}

VCS_F_UNSTAGED(){
    VCS_UNSTAGED=$(git status --porcelain |sed 's/^ //'| grep ^M | wc -l);
    VCS_S_UNSTAGED="!"
    if [[ "$VCS_UNSTAGED" > 0 ]]; then
	VCS_P_UNSTAGED="${VCS_S_UNSTAGED}${VCS_UNSTAGED}";
	echo -n " " | cat - <(echo -n "${VCS_P_UNSTAGED}" | xargs) | tr -d '\n';
    fi
}

VCS_F_UNTRACKED(){
    VCS_UNTRACKED=$(git status --porcelain |sed 's/^ //'| grep ^"??" | wc -l);
    VCS_S_UNTRACKED="?"
    if [[ "$VCS_UNTRACKED" > 0 ]]; then
	VCS_P_UNTRACKED="${VCS_S_UNTRACKED}${VCS_UNTRACKED}";
	echo -n " " | cat - <(echo -n "${VCS_P_UNTRACKED}" | xargs) | tr -d '\n';
    fi
}

VCS_PROMPT(){
    VCS_BRANCH=$(git branch --show-current 2>/dev/null);
    if [ "$VCS_BRANCH" ]; then
	echo -n "($VCS_BRANCH$(VCS_F_BEHIND)$(VCS_F_AHEAD)$(VCS_F_UNCOMMITED)$(VCS_F_UNSTAGED)$(VCS_F_UNTRACKED))";
    fi
}

###PROMPT
prompt() {
    L1="\u@sandbox:\w jobs:\j";
    R1="$(VCS_PROMPT)";
    L2="\n>$AE";
    PS1=$(printf "%s%*s%s%s%s" "$GREEN" "$(tput cols)" "$R1\r" "$MPC" "$L1" "$L2");
}
PROMPT_COMMAND=prompt

###tools
newtask() {
    touch $1;
    echo '#include "main.h"' >> $1;
    echo "" >> $1;
    echo "/**" >> $1;
    echo " * $2 -" >> $1;
    echo " */" >> $1;
    echo "$2" >> $1;
    echo "{" >> $1;
    echo "}" >> $1;
    }

# Aliases
# export PATH="/home/bgtfraser/holbertonschool-low_level_programming/utils/scripts:$PATH"

# Git Configs
git config --global user.name "bfrasholb"
git config --global user.email "13065@holbertonstudents.com"
git config --global credential.helper 'cache --timeout=7200000000'
git config advice.addIgnoredFile false