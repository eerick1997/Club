\LoadClass{article}
\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{resume}[2019/09/04 erick's resume class]

\RequirePackage[margin=0.5in]{geometry}
\RequirePackage{titling}
\RequirePackage{titlesec}
\RequirePackage{tikz}
\RequirePackage{fontawesome}
\RequirePackage{multicol}
\RequirePackage{hyperref}
\RequirePackage{longtable}
\usetikzlibrary{fit, positioning, calc}

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
    \href{#2}{#1\faExternalLink}
}

%School name
%Title 
%Date 
%Score
\newcommand{\school}[4]{
    \raggedright\textbf{#1} \hfill \raggedright{#3} \break
    \raggedright\textbf{#2} \hfill \raggedright#4
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
    \textsf{#1} \hfill {#2} \break
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
    \centerline{\color{deepblue}\textbf{\Huge{#1}}}
}

\newcommand{\partitle}[1]{
    \textbf{\Large{\color{deepblue} #1 }}\break
}

%1.Email
%2.Github
%3.Linkedin
%4.Mobile phone
\newcommand\contact[4]{
    \begin{longtable}[c]{ll}
        \color{deepblue}\raggedright{\faGoogle: }{#1} & \color{deepblue}{\faGithub: }{#2} \\
        \color{deepblue}\raggedright{\faLinkedin: }{#3} & \color{deepblue}{\faMobilePhone: }{#4}
        \endfirsthead
        \endhead
    \end{longtable}
}