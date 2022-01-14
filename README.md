# STRUCTURE DES DONNÉES - GRAPHES - C++


## Application console Alerte COVID

Avec la propagation du Covid-19, il est primordial qu'on développe des applications de traçage pour mieux monitorer la propagation du virus.
Mon applications de traçage utilise des graphes dont les sommets représentent des personnes et dont les arcs représentent la puissance d’un signal Bluetooth qui estime la distance entre les personnes.
L’interaction se fait au moyen d’une interface de la console (version graphique s'en vient).

Cette application Alerte COVID diffère légèrement de la version originale puisque celle-ci est juste une simulation pour consolider mes connaissances des graphes apprises lors du cours de Structures des données (Inf2010) et du cours de Structure Discrète (Log2810).

### Contraintes de l’application : 
Le fichier individus.txt recense tous les individus que l'application prend en compte, ainsi qu’un tag pour indiquer si un individu a eu un diagnostic positif à la Covid (1) ou non (0). Chaque individu porte un nom unique pour alleger les fichiers textes.

Le fichier contacts.txt recense tous les contacts existants entre les individus, ainsi que la distance entre des personnes.

L’application permet à une personne de vérifier si elle a été exposée au COVID au cours des 14 derniers jours.

Le contact entre deux personnes doit avoir été étroit, soit à moins de deux mètres pour lui considérer exposé à la Covid.


## Note :

**L’option (a)** permet de créer le graphe à partir des fichiers d’individus et de contacts

**L’option (b)** permet d’afficher dans la console le résultat du graphe d’exposition. Cette option ne peut pas être choisie avant l’option (a)

**L’option (c)** quant à elle, permet de déterminer si une personne a été exposée au COVID. Pour ce faire,le nom
d’une personne doit être demandé par la console. Cette option ne peut pas être choisie avant
l’option (a)
