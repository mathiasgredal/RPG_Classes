# RPG Classes #

Dette repository vil blive brugt til at lærer hvordan man bruger klasser i C++.



## Logbog

### 2020/03/13

I dag gik vi igang med et projekt omkring hvordan man bruger klasser i c++, først gik vi igennem teorien ved brug af internetlæringsvideoer på youtube, da det foregik hjemmefra. Da videoerne var ret lange, blev de set på 1,75x hastighed. Herefter blev opgavebeskrivelsen læst hvorefter opgave 1 blev lavet. Det foregik ved først at sætte et repository op på både Github og Bitbucket. Herefter blev projektet lavet og IDE blev sat op med filerne nødvendige for at løse opgaven. 

 

Der blev først lavet en klass hvor de forskellige metoder og medlemvariabler blev sat op. For at gemme dataen blev der lavet en struct ved navn Character, hvori der blev gemt navn, xp og level. I party klassen blev der lavet en vector til at holde charactersne. 

Inden hver funktion blev lavet, så blev der skrevet nogle få kommentare til hvordan funktionen skulle forløbe, herefter blev implementeringen lavet. Der blev desvære taget brug af en goto i funktionen read_xp_level. Til sorteringen blev den indbyggede std::sort brugt.  Der blev også brugt Boost, til nogle funktioner f.eks. til at konverterer strenge til små bogstaver og til at trimme strenge.



### 2020/03/17

I dag blev opgaverne 2, 3 og 4 lavet, som bestod af at implementere klasserne `Equipment`, `Character` og `Shop`. Først blev der defineret de forskellige private medlemsvariabler som klassen skulle bruge, hvorefter der blev lavet nogle offentlige Getter funktioner. Disse funktioner gør at man nemmere kan vælge hvordan dataen i klassen kan modificeres og sørge for at dataen ikke lige pludslig kommer i en ulovlig tilstand fordi en variabel blev ændret uhensigtsmæssigt.  Getteren samt print metoden blev sat som ```const ```,  så man ved at metoden ikke kan ændre på dataen, og derfor er den sikker at kalde fra en anden funktion, som har fået en konst reference, hvilket tages brug af i den for løkke som bruges til at printe alt equipment for en character. For at genererer de id hver character har, så bruges Boost biblioteket. I equipment klassen blev der brugt en enum, til at holde styr på hvilken type udstyr det var. Det gode ved en enum klasse er at de forskellige typer at klart defineret og samlet. Dog er det svært at printe navnet ud for dem, og man har derfor brug for en hjælpefunktion med en switch som tager en enum ind og returnere en streng. 

For at teste programmet blev der lavet en simpel while loop, hvor man kan indtaste en kommando og så bliver den tilhørende funktion kaldet. Her kan man også indtaste print funktionerne for at se hvordan dataen bliver ændret. 



