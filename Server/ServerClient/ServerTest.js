var http = require('http');
var url = requre('url');
var port = 8000;
var msgLength = 100;

var besked = {
	name: "Derpbina",
	msg: "Har ikke taget sine piller"
}

var postOptions = {
	host: localhost,
	port: port, 
	path: "/duckmaster3001_raspberry", 
	method: "POST",
	header: {
		"Content-type": "application/json",
		"Content-length": msgLength
	}
}

var httpRequest = http.request(postOptions, function(result){});

httpRequest.write(JSON.stingify(besked);
httpRequest.end();