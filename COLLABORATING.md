**Bemærk: Tekst mellem < og > betyder "indsæt egen tekst her", og krokodille-næbbene skal IKKE med. Feks. kan du indsætte 
`userClass` i stedet for `<ny-branch-navn>`.**

1. Klon repo til semesterprojektet (**Skal kun gøres én gang**).  
`git@github.com:BjornNorgaard/DuckMaster3001.git`

2. Lav en ny branch.  
`git checkout -b <ny-branch-navn>` 
Navnet skal være på følgende form: ditNavn-branchNavn.
Så hvis jeg vil oprette en branch, som skal bruges til koden for brugerklassen: 
`git checkout -b bjorn-userclass`
Giv branchen et navn, der kort giver en idé om, hvad branchen indeholder kode til. (F.eks. seriel, ny-menu, nasa-rumskib-software).

3. Skriv kode, det bedste du har lært og sørg løbende for at updatere din branch så den er magen til master:  
`git pull origin master`  
Dette er især vigtigt hvis flere skriver kode samtidigt!

4. Test det kode du har lavet.

5. Commit ændringen.  
Hvis du kun har ændret i eksisterende filer:  
`git commit -m "<besked til admin>"`  
Hvis du har lavet nye filer:  
`git add <ny-fil>`  
Commit derefter koden for at lave et "snapshot".  
`git commit -m "<besked til admin>"`

6. Enten fortsæt med at skrive mere kode efter commit'en (gå tilbage til pkt. 3).  
Eller hvis du er færdig - gå videre til push.

7. Push til remote repo:  
`git push origin <branch-navn>`
og branch-navn er selvfølgelig navnet på den branch du er på nu.

8. Opret pull request:
Gå ind på repo på [github](https://github.com/BjornNorgaard/DuckMaster3001) og opret ny pull request.

![Opret pull request](https://github.com/BjornNorgaard/DuckMaster3001/blob/master/Pictures/CollaborationGuide/pull_request_01.png)

![Bekræft pull request](https://github.com/BjornNorgaard/DuckMaster3001/blob/master/Pictures/CollaborationGuide/pull_request_02.png)

Sæt en af os andre på som *assignee* og vent på svar.  
Når de nødvendige ændringer er lavet vil personen som har kigget din kode igennem vælge at *merge* din branch.

![Merge branch](https://github.com/BjornNorgaard/DuckMaster3001/blob/master/Pictures/CollaborationGuide/pull_request_03.png)

![Confirm merge](https://github.com/BjornNorgaard/DuckMaster3001/blob/master/Pictures/CollaborationGuide/pull_request_04.png)

Nedstående skal **KUN** gøres hvis personen selv beder om det i sin pull request

![Delete branch](https://github.com/BjornNorgaard/DuckMaster3001/blob/master/Pictures/CollaborationGuide/pull_request_05.png)
