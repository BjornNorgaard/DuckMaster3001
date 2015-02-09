 # Kode til projektet #

**Bemærk: Tekst mellem < og > betyder "indsæt egen tekst her", og krokodille-næbbene skal IKKE med. Feks. kan du indsætte `menusystem` i stedet for `<ny-branch-navn>`.**

1. Klon repo Semesterprojekt2  
`git clone git@github.com:BjornNorgaard/semesterprojekt3.git`

2. Lav en ny branch  
`git checkout -b <ny-branch-navn>`  
Navnet skal være på følgende form: forbogstav-branchNavn.
Så hvis Bjørn vil oprette en branch: b-branchNavn.
Giv branchen et navn, der kort giver en idé om, hvad branchen indeholder kode til. (F.eks. seriel, ny-menu, nasa-rumskib-software).

3. Skriv kode, det bedste du har lært.

4. Test det kode du har lavet

5. Commit ændringen  
Hvis du kun har ændret i eksisterende filer:  
`git commit -m "<besked til admin>`  
Hvis du har lavet nye filer:  
`git add .`
`git commit -m "<besked til admin>"`

6. Enten fortsæt med at skrive mere kode efter commit'en (gå tilbage til pkt. 3)  
Eller hvis du er færdig - gå videre til push.

7. Push til remote repo:  
`git push origin <branch-navn>`
