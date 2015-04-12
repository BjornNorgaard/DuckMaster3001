var http = require('http');
var url = require('url');
var port = 8000;
var msgLength = 100;
var retryAttempt = 1;

var besked = {
	name: "Derpbina",
	msg: "Har ikke taget sine piller"
}

var msgDerp = JSON.stringify(besked);

var postOptions = {
	host: '10.0.0.13',
	port: port, 
	path: '/duckmaster3001_raspberry', 
	method: 'POST',
	header: {
		'Content-Type': 'application/json',
		'Content-Length': msgDerp.length
	}
}

var transmit = function() {
	var httpRequest = http.request(postOptions, function(result){});
	
	httpRequest.on("error", function(e){	
		if(retryAttempt <= 20) {
			p(retryAttempt + "nd attempt.");
			transmit();
		
			retryAttempt++;
		}
		else if(retryAttempt == 20) {
			p(e);
		}
	})
	
	httpRequest.write(msgDerp);
	httpRequest.end();	
}

var p = function(output) {
	console.log(output);
}

transmit();
