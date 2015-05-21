/*nærmere forklaring af variabler ønskes, spørg Jensen*/
var http = require('http');	/*includes*/
var url = require('url');	/*includes*/
var port = 8000;			/*port nummer som skal reserveres*/
var msgLog = [];			/*variable til at gemme div. beskeder, indtil de er læst*/

/*hjælpefunktion til udskrift i terminal*/
var p = function(output) {
	console.log(output);
} 

/*request er hvad serveren bliver spurgt om og response er hvor svaret til request bliver sendt*/
var derpFunc = function(request, response) {
	var pathname = url.parse(request.url).pathname;
	
	/*hvis det er raspberry som vi kommunikere med, så...*/
	if(pathname == "/duckmaster3001_raspberry") {
		
		/*hvis raspberry vil "poste"...*/
		if(request.method == "POST") {	

			/*variable til at gemme/samle beskeden i*/
			var body = "";
			
			/*modtager data indtil den fulde længde er modtaget*/
			request.on("data", function(data) {

				/*udskrift så vi kan se at det virker*/
				p("receiving...");
				
				/*tilføjer ny del af besked til den allerede modtagne*/
				body += data;
			})
			
			// Done receiving data, now saving
			/*færdig med at modtage data, nu skal beskeden konverteres
			fra JSON til noget vi bedre kan læse og så udskrives beskeden*/
			request.on("end", function() {

				/*den modtagne besked konverteres og gemmes i msg*/
				var msg = JSON.parse(body);
				p("transfer complete!");
				
				/*msgLog er en "vector" som vi kan pushe beskederne til*/
				msgLog.push(msg);
				
				/*text/plain er fordi der ikke er noget svar men man skal definere en type på dataen*/
				response.writeHeader(200, {"Content-Type": "text/plain"});

				/*udskriver beskeden i consolen når den er modtaget*/
				console.log(msg);
			})
		}
	}

	/*hvis det er android applikationen vi kommunikere med...*/
	else if(pathname == "/duckmaster3001_application") {
		
		/*hvis den vil "hente" data*/
		if(request.method == "GET") {

			/*variable hvis indhold skal sendes*/	
			var sendData;
			
			/*hvis vi ikke har modtaget noget er msgLog længden naturligt = 0*/
			if(msgLog.length == 0) {
				sendData = {msg: "Nothing New"};
			}
			else {
				/*rydder den plads i "vectoren" som nu er læst*/
				sendData = msgLog.shift();
			}
			
			/*melder tilbage at alt gik godt (200 = OK) og at det den får skal læses som 
			noget af typen JSON*/
			response.writeHeader(200, {"Content-Type": "application/json"});

			/*data konverteres til JSON og sendes*/
			response.write(JSON.stringify(sendData));
		}
	}
	
	/*færdig for denne omgang*/
	response.end();
}

/*reservere porten port og lytter efter request på den*/
http.createServer(derpFunc).listen(port);
