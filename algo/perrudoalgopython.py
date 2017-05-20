palifico = 0

#   VARIABLES
#       a : nombre de dés de la précédente mise
#       x : valeur du dé de la précédente mise
#       Palifico : Booléen qui indique que le tour de jeu est en Palifico ou non


def misesuivante(a,x):

    Palifico = False
    
    #Vérification de la MISE PRECEDENTE

    if x < 1 or x > 6 or a < 1:
        return print("La précédente mise est incorrecte")

    if Palifico is False:

        listevaleur = [1] #1 est par défaut dans la liste car on pourra toujours utiliser les toucan (à part en palifico)

        for n in range (x,7):
            
            if n !=1:
                listevaleur.append(n)
                
        
    if Palifico is True :

        listevaleur = [] #La liste ne comprendra qu'une seule valeur et n'en possèdera pas par défaut
        listevaleur.append(x)
        

    return listevaleur
    

