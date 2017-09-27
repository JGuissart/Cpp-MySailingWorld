.SILENT:

COMPIL = g++ -I $(LIB)

LIB = Lib

Applic:	main.o $(LIB)/Activite.o $(LIB)/Circuit.o $(LIB)/Concurrent.o $(LIB)/FichierCircuits.o $(LIB)/FichierRegates.o $(LIB)/FichierUsers.o $(LIB)/FonctionsAdmin.o $(LIB)/FonctionsCircuit.o $(LIB)/FonctionsClub.o $(LIB)/FonctionsRegate.o $(LIB)/FonctionsRegateChoisie.o $(LIB)/InvalidContainersException.o $(LIB)/InvalidMomentException.o $(LIB)/Iterateur.o $(LIB)/MaListeTriee.o $(LIB)/ModeleObjetFlottant.o $(LIB)/Moment.o $(LIB)/ObjetFlottant.o $(LIB)/Point.o $(LIB)/Regate.o $(LIB)/User.o $(LIB)/Vecteur.o $(LIB)/Pause.o
	echo Creation de l'executable Applic ...
	$(COMPIL) main.o $(LIB)/Activite.o $(LIB)/Circuit.o $(LIB)/Concurrent.o $(LIB)/FichierCircuits.o $(LIB)/FichierRegates.o $(LIB)/FichierUsers.o $(LIB)/FonctionsAdmin.o $(LIB)/FonctionsCircuit.o $(LIB)/FonctionsClub.o $(LIB)/FonctionsRegate.o $(LIB)/FonctionsRegateChoisie.o $(LIB)/InvalidContainersException.o $(LIB)/InvalidMomentException.o $(LIB)/Iterateur.o $(LIB)/MaListeTriee.o $(LIB)/ModeleObjetFlottant.o $(LIB)/Moment.o $(LIB)/ObjetFlottant.o $(LIB)/Point.o $(LIB)/Regate.o $(LIB)/User.o $(LIB)/Vecteur.o $(LIB)/Pause.o -o Applic

$(LIB)/Activite.o:	$(LIB)/Activite.h $(LIB)/ObjetFlottant.h
	echo Creation de Activite.o ...
	$(COMPIL) $(LIB)/Activite.cxx -c
	mv Activite.o $(LIB)

$(LIB)/Circuit.o:	$(LIB)/Circuit.h $(LIB)/FichierCircuits.h
	echo Creation de Circuit.o ...
	$(COMPIL) $(LIB)/Circuit.cxx -c
	mv Circuit.o $(LIB)

$(LIB)/Concurrent.o:	$(LIB)/Concurrent.h
	echo Creation de Concurrent.o ...
	$(COMPIL) $(LIB)/Concurrent.cxx -c
	mv Concurrent.o $(LIB)

$(LIB)/FichierCircuits.o:	$(LIB)/FichierCircuits.h $(LIB)/Circuit.h
	echo Creation de FichierCircuits.o ...
	$(COMPIL) $(LIB)/FichierCircuits.cxx -c
	mv FichierCircuits.o $(LIB)

$(LIB)/FichierRegates.o:	$(LIB)/FichierRegates.h
	echo Creation de FichierRegates.o ...
	$(COMPIL) $(LIB)/FichierRegates.cxx -c
	mv FichierRegates.o $(LIB)

$(LIB)/FichierUsers.o:	$(LIB)/FichierUsers.h $(LIB)/User.h $(LIB)/MaListeTriee.h
	echo Creation de FichierUsers.o ...
	$(COMPIL) $(LIB)/FichierUsers.cxx -c
	mv FichierUsers.o $(LIB)

$(LIB)/FonctionsAdmin.o:	$(LIB)/FonctionsAdmin.h $(LIB)/MaListeTriee.h $(LIB)/Iterateur.h 
	echo Creation de FonctionsAdmin.o ...
	$(COMPIL) $(LIB)/FonctionsAdmin.cxx -c
	mv FonctionsAdmin.o $(LIB)

$(LIB)/FonctionsCircuit.o:	$(LIB)/FonctionsCircuit.h $(LIB)/Circuit.h $(LIB)/FichierCircuits.h
	echo Creation de FonctionsCircuit.o ...
	$(COMPIL) $(LIB)/FonctionsCircuit.cxx -c
	mv FonctionsCircuit.o $(LIB)

$(LIB)/FonctionsClub.o:	$(LIB)/FonctionsClub.h $(LIB)/FonctionsCircuit.h $(LIB)/FonctionsRegate.h $(LIB)/FonctionsRegateChoisie.h
	echo Creation de FonctionsClub.o ...
	$(COMPIL) $(LIB)/FonctionsClub.cxx -c
	mv FonctionsClub.o $(LIB)

$(LIB)/FonctionsRegate.o: $(LIB)/FonctionsRegate.h $(LIB)/MaListeTriee.h $(LIB)/Iterateur.h
	echo Creation de FonctionsRegate.o ...
	$(COMPIL) $(LIB)/FonctionsRegate.cxx -c
	mv FonctionsRegate.o $(LIB)

$(LIB)/FonctionsRegateChoisie.o:	$(LIB)/FonctionsRegateChoisie.h $(LIB)/Concurrent.h $(LIB)/MaListeTriee.h $(LIB)/Vecteur.h
	echo Creation de FonctionsRegateChoisie.o ...
	$(COMPIL) $(LIB)/FonctionsRegateChoisie.cxx -c
	mv FonctionsRegateChoisie.o $(LIB)
	
$(LIB)/InvalidContainersException.o:	$(LIB)/InvalidContainersException.cxx $(LIB)/InvalidContainersException.h
	echo Creation de InvalidContainersException.o ...
	$(COMPIL) $(LIB)/InvalidContainersException.cxx -c
	mv InvalidContainersException.o $(LIB)

$(LIB)/InvalidMomentException.o:	$(LIB)/InvalidMomentException.cxx $(LIB)/InvalidMomentException.h
	echo Creation de InvalidMomentException.o ...
	$(COMPIL) $(LIB)/InvalidMomentException.cxx -c
	mv InvalidMomentException.o $(LIB)

$(LIB)/Iterateur.o:	$(LIB)/Iterateur.h $(LIB)/User.h $(LIB)/Regate.h $(LIB)/Concurrent.h
	echo Creation de Iterateur.o ...
	$(COMPIL) $(LIB)/Iterateur.cxx -c
	mv Iterateur.o $(LIB)

$(LIB)/MaListeTriee.o:	$(LIB)/MaListeTriee.h $(LIB)/User.h $(LIB)/Regate.h $(LIB)/Concurrent.h $(LIB)/Pause.h
	echo Creation de MaListeTriee.o ...
	$(COMPIL) $(LIB)/MaListeTriee.cxx -c
	mv MaListeTriee.o $(LIB)

$(LIB)/ModeleObjetFlottant.o:	$(LIB)/ModeleObjetFlottant.h
	echo Creation de ModeleObjetFlottant.o ...
	$(COMPIL) $(LIB)/ModeleObjetFlottant.cxx -c
	mv ModeleObjetFlottant.o $(LIB)

$(LIB)/Moment.o:	$(LIB)/Moment.h $(LIB)/InvalidMomentException.h
	echo Creation de Moment.o ...
	$(COMPIL) $(LIB)/Moment.cxx -c
	mv Moment.o $(LIB)

$(LIB)/ObjetFlottant.o:	$(LIB)/ObjetFlottant.h $(LIB)/ModeleObjetFlottant.h
	echo Creation de ObjetFlottant.o ...
	$(COMPIL) $(LIB)/ObjetFlottant.cxx -c
	mv ObjetFlottant.o $(LIB)

$(LIB)/Pause.o:	$(LIB)/Pause.h
	echo Creation de Pause.o ...
	$(COMPIL) $(LIB)/Pause.cxx -c
	mv Pause.o $(LIB)

$(LIB)/Point.o:	$(LIB)/Point.h
	echo Creation de Point.o ...
	$(COMPIL) $(LIB)/Point.cxx -c
	mv Point.o $(LIB)

$(LIB)/Regate.o:	$(LIB)/Regate.h $(LIB)/Moment.h
	echo Creation de Regate.o ...
	$(COMPIL) $(LIB)/Regate.cxx -c
	mv Regate.o $(LIB)

$(LIB)/User.o:	$(LIB)/User.h
	echo Creation de User.o ...
	$(COMPIL) $(LIB)/User.cxx -c
	mv User.o $(LIB)

$(LIB)/Vecteur.o: $(LIB)/Vecteur.h $(LIB)/Point.h $(LIB)/Concurrent.h $(LIB)/InvalidContainersException.h
	echo Creation de Vecteur.o ...
	$(COMPIL) $(LIB)/Vecteur.cxx -c
	mv Vecteur.o $(LIB)

main.o:	$(LIB)/User.h $(LIB)/FichierUsers.h $(LIB)/MaListeTriee.h $(LIB)/FonctionsAdmin.h $(LIB)/FonctionsClub.h $(LIB)/FonctionsRegate.h $(LIB)/Concurrent.h $(LIB)/Regate.h $(LIB)/Pause.h
	echo Creation de main.o ...
	$(COMPIL) main.cxx -c		

clean:
	rm -f Applic main.o $(LIB)/*.o core
