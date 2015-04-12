var http = require('http');
var url = require('url');
var port = 8000;

var postOptions = {
	host: '127.0.0.1',
	port: port, 
	path: '/duckmaster3001_application', 
	method: 'GET',
	header: {
		'Content-Type': 'text/plain',
		'Content-Length': 0
	}
}

var receive = function() {
	var httpRequest = http.request(postOptions, function(result){
		var body = "";
			
		// Receive part of the data
		result.on("data", function(data) {
			p("request.on: data");	
			body += data;
		})
		
		// Done receiving data, now saving
		result.on("end", function() {
			var msg = JSON.parse(body);
			
			console.log(msg);
		})
	});

	httpRequest.end();
	
	setTimeout(receive, 2000);
	p("Sender");
}

var p = function(output) {
	console.log(output);
}

receive();
