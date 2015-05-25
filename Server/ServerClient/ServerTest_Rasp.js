var http = require('http');	/*includes*/
var url = require('url');	/*includes*/
var port = 8000;			/*port nummer som skal reserveres*/
var retryAttempt = 1;		/**/

/*Hjælpefunktion til udskrift i terminal*/
var p = function(output) {
	console.log(output);
}

// Besked som sendes.
var besked = {
	name: "Derpbina",
	msg: "Har ikke taget sine piller"
}

/*"Klasse" som konvertere vores besked til en string som vi kan udpakke
når den er modtaget på den anden side, MEGET nemmere at sende ting på
denne måde*/
var msgDerp = JSON.stringify(besked);

/*Nærmere forklaring af variabler ønskes her:*/
var postOptions = {
	host: '192.168.43.197',					/*intern ip, som enheden er på*/
	port: port, 
	path: '/duckmaster3001_raspberry', 		/*https://domæne.com/path, hvor /duck... er path på intern ip som er domæne*/
	method: 'POST', 						/*hvad denne postOption skal kunne, post = sende*/
	header: {
		'Content-Type': 'application/json',	/*type af besked som skal sendes*/
		'Content-Length': msgDerp.length 	/*længden af beskeden, afgør hvor længe modtager "lytter"*/
	}
}

var transmit = function() {
	/*call-back funktion som smider function i køen og kalder den med result når den er klar*/
	var httpRequest = http.request(postOptions, function(result){});
	
	//e er et error event med info om fejlen
	httpRequest.on("error", function(e){
		/*I tilfælde af at beskeden ikke kunne sendes, prøver systemet bare
		at sende bekseden igen, hvilket den så bliver ved med. Efter at have
		testet hvor mange gange det højest kan mislykkes på dette netværk
		(9 gange) er 20 valgt som antal førsøg før den giver op*/

		if(retryAttempt <= 20) {
			/*Udskrift af antal forsøg før vellykket transmission*/
			p(retryAttempt + "nd attempt.");
			transmit();

			retryAttempt++;
		}
		else if(retryAttempt == 20) {
			/*e er den error som er kastet som gerne skulle beskrive fejlen*/
			p(e);
		}
	})
	
	/*sender beskeden, via den indbyggede funktion write*/
	httpRequest.write(msgDerp);

	/*Afslutter transmissionen*/
	httpRequest.end();	
}

/*funktionskald, det øverste er bare definitionen*/
transmit();
