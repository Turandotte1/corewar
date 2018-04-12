# corewar
Projet de l'école 42 qui a pour but de faire affronter des programmes .cor dans une machine virtuelle.

Fin de la partie : plus de processus en vie. 

Le gagnant est le dernier qui a fait live (avec affichage du gagnant). 

4 champions max, le dernier processus joue en premier sauf indication contraire. 

## 3 Parties:
 ### Executable ASM
 Interprète le code d'un champion en assembleur vers un binaire (fichier .s-> fichier .cor).
 
 ### Machine Virtuelle 
 Sert d'arène pour les champions (possibilité de plusieurs exécutables sur la machine), les champions sont équidistants.
 
 #### Arene
 * **CYCLE_TO_DIE** : Nombre de cycles entre chaque vérification des lives de chaque processus. 
 * **NBR_LIVE** : Seuil de mort subite. Si lors d'une verification, le nombre de live comptés dépasse ce seuil, *CYCLE_TO_DIE* est décrémenté de *CYCLES_DELTA* cycles.
 * **CYCLE_DELTA** : La variation de *CYCLE_TO_DIE* a chaque mort subite.
 * **MEM_SIZE** : Taille de la memoire de l'arène.
 * **MAX_CHECK** : Si *MAX_CHECK* vérifications des lives sont effectuées à la suite sans jamais déclencher de mort subite, *CYCLE_TO_DIE* est décrémenté de *CYCLES_DELTA* cycles.
 * **CHAMP_MAX_SIZE** : Taille maximale d'un champion.
 * **CYCLE** : Definis dans op.c pour chaque instruction.
 * **IDX_MOD** : Portée max de certaines opérations (hors lfork).
 * **REG_NUMBER** : Nombre de registres disponible pour chaque processus.
 * **REGISTRE** : Espace mémoire propre à chaque processus, accessible rapidement.
 * **REG_SIZE** : Taille d'un registre en octet.
 
 #### Processus
 * PC : Codé sur 2 octets, représente le décalage en cases entre le point de depart du processus et l'instruction courante. Autrement dit, il designe la postion de l'instruction courante du processus par rapport au point d'adressage effectif.
 #### CARRY:
  Un flag/booléen, qui vaut 1 si la dernière opération a réussi. Seules certaines opérations peuvent modifier le carry.
  
 #### modélisation des operations : {1, 2, 3, 4, 5, 6, 7, 8},
 1. Description de l'opération.
 2. Nombre d'arguments.
 3. Type des arguments (DIR | REG | IND).
 4. Référence de l'argument.
 5. Nombre de cycle à attendre avant de lancer l'exécution.
 6. Message à afficher.
 7. Modifie le carry.
 8. Taille du direct (4 | 2).

 Exemple :
 ```
 {"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1}
 ```
 Pour plus de précisions, cf sheet cheat présente dans le projet.

### Champion
Les 139 premières lignes correspondent au header dans le .cor (affichage a regarder).
