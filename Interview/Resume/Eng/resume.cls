\LoadClass{article}
\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{resume}[2019/09/04 erick's resume class]

\RequirePackage[margin=0.2in]{geometry}
\RequirePackage{titling}
\RequirePackage[compact]{titlesec}
\RequirePackage{tikz}
\RequirePackage{fontawesome}
\RequirePackage{multicol}
\RequirePackage{hyperref}
\RequirePackage{longtable}
\RequirePackage{xcolor, colortbl}
\usetikzlibrary{fit, positioning, calc}
\RequirePackage[framemethod=TikZ]{mdframed}
\usepackage{enumitem}

%%%%%%%%%%%%%%%%%% SOME COLORS %%%%%%%%%%%%%%%%%%
\definecolor{deepblue}{RGB}{0, 9, 100}

\titleformat{\section}
    {\color{deepblue}\Large\scshape\raggedright}
    {}{0em}
    {}
    [{\color{deepblue}\titlerule[2pt]}]

\titleformat{\subsection}
    {\large\scshape\raggedright}
    {}{0em}
    {}

\newcommand{\resumesection}[2]{
    \section[]{\textbf{#1 #2}}
}

\newcommand{\divider}{
    {\color{deepblue}\titlerule[2pt]}\break
}

\newcommand{\link}[2]{
    \href{#2}{#1}
}

%School name
%Title 
%Date 
%Score
\newcommand{\school}[4]{
    
    \hspace{-0.1cm}\raggedright\textbf{#1} \hfill \raggedright{#3} \break
    \raggedright\textbf{#2} \hfill \raggedright#4 \vspace*{0.2cm}
}

%Title
%Description
\newcommand{\project}[ 2 ]{
    \subsection[#1]{\textbf{\color{deepblue}#1}} \raggedright#2
}

%name
%description
%date
\newcommand{\award}[3]{
    \subsection[#1]{\textbf{\color{deepblue}#1}} #2 \hfill #3
}

\newcommand{\programminglanguage}[2]{
    \textsf{#1} \hfill {#2} \break
}

\newcommand{\technology}[2]{
    \textsf{#1} \hfill {#2}
}

\newcommand{\platform}[2]{
    \textsf{#1} \break
}

\newcommand{\idiom}[2]{
    \textsf{#1} \hfill {#2} \break
}

\newcommand{\datesection}[2]{
    \section[#1]{#1 \hfill #2 }
}

\newcommand{\datedsubsection}[2]{
    \subsection[#1]{#1 \hfill #2}
}

\newcommand{\name}[1]{
    \centerline{\color{white}\textbf{\LARGE{#1}}}
}

\newcommand{\partitle}[1]{
    \textbf{\Large{\color{deepblue} #1 }}\break
}

%Title
%place
%description
\newcommand{\experienceitem}[3]{
    \subsection[#1]{\textbf{\color{deepblue}#1} / \textsf{#2}} \raggedright#3
}

\newcommand{\extrainfo}[1]{
    \textsf{#1} \break
}

\arrayrulecolor{white}
%1.Email
%2.Github
%3.Linkedin
%4.Mobile phone
\newcommand\contact[4]{
    \begin{longtable}{l|l|l|l}
        \color{white}\raggedright{\faGoogle: }{\Large{#1}} & \color{white}{\faGithub: }{\Large{#2}} &
        \color{white}\raggedright{\faLinkedin: }{\Large{#3}} & \color{white}{\faMobilePhone: }{\Large{#4}}
        \endfirsthead
        \endhead
    \end{longtable}
}

\newenvironment{itemize*}%
  {\begin{itemize}%
    \setlength{\itemsep}{-0.5cm}%
    \setlength{\parskip}{-0.5cm}}%
{\end{itemize}}