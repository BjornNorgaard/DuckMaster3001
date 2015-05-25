var http = require('http');	/*includes*/
var url = require('url');	/*includes*/
var port = 8000;			/*port nummer som skal reserveres*/

var postOptions = {
	host: '192.168.43.197',					/*intern ip som enheden er på*/
	port: port, 							/*indstilling af port*/
	path: '/duckmaster3001_application', 	/*https://domæne.com/path, hvor /duck... er path på intern ip som er domæne*/
	method: 'GET',							/*"beskeden" som sendes med denne, vil være en "læse-anmodning"*/
	header: {
		'Content-Type': 'text/plain',		/*type af besked som skal modtages*/
		'Content-Length': 0					/*GET sender ikke noget data, derfor 0*/
	}
}

/*hjælpefunktion til at udskrie i terminalen*/
var p = function(output) {
	console.log(output);
}

/*modtage funktionen ser ud som følger:*/
var receive = function() {

	/*call-back funktion som smider function i køen og kalder den med result når den er klar*/
	var httpRequest = http.request(postOptions, function(result){

		/*variable til at gemme modtaget data i*/
		var body = "";
			
		/*modtager en del af dataen*/
		result.on("data", function(data) {
			p("receiving...");	
			
			/*opbygger en string med modtaget data*/
			body += data;
		})
		
		/*færdig med at modtage, gemmer nu*/
		result.on("end", function() {
			p("transfer complete!");

			/*gemmer modtaget besked efter konvertering fra JSON til læsebar type*/
			var msg = JSON.parse(body);
			
			/*udskriver modtaget besked*/
			console.log(msg);
		})
	});

	/*færdig med at modtage*/
	httpRequest.end();
	
<<<<<<< HEAD
	// polling frequency in milliseconds
	setTimeout(receive, 1000);
}

var p = function(output) {
	console.log(output);
=======
	/*hvor ofte appen tjekker for nye beskeder.
	fungere ved at smide funktionen "receive" om 
	bag i køen sådan at den bliver kaldt om 1 sek.*/
	setTimeout(receive, 1000);
>>>>>>> 4476ca4355fa90779803eeb39fbeb93e136039e7
}

/*Kald til funktion*/
receive();
