# Création d'une librairie en assembleur au sein du cursus de 42.
## Consigne de rendu
Votre librarie doit s’appeller libasm.a
- Vous devez rendre un main qui testera vos fonctions et compilera avec votre librairie montrer qu’elle fonctionne.
- Vous devez écrire les fonctions suivantes :
	- ft_strlen (man 3 strlen)
	- ft_strcpy (man 3 strcpy)
	- ft_strcmp (man 3 strcmp)
	- ft_write (man 2 write)
	- ft_read (man 2 read)
	- ft_strdup (man 3 strdup, malloc autorisé)

## Ressources:
NASM Assembly quick Reference ("Cheat Sheet")
- [cs.uaf.edu](https://www.cs.uaf.edu/2017/fall/cs301/reference/x86_64.html)
- [cs.brown.edu](https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf)

macOS BSD System Calls
- [sigsegv](https://sigsegv.pl/osx-bsd-syscalls/)

NASM Tutorial
- [cs.lmu.edu](https://cs.lmu.edu/~ray/notes/nasmtutorial/)

Assembleur
- [alixis.nasr](http://pageperso.lif.univ-mrs.fr/~alexis.nasr/Ens/Compilation/cm06_x86.pdf)

Appels system
- [syscalls] (http://syscalls.kernelgrok.com/)

Pour ft_list_push_front
- [Alignement de la stack](https://stackoverflow.com/questions/4175281/what-does-it-mean-to-align-the-stack)
- [Gestion du push front](https://stackoverflow.com/questions/39474332/assembly-difference-between-var-and-var/39474660)

