var http = require('http');
var url = require('url');
var port = 8000;

var postOptions = {
	host: '10.0.0.13',
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
			p("receiving...");	
			
			// assembling full dataset
			body += data;
		})
		
		// Done receiving data, now saving
		result.on("end", function() {
			p("transfer complete!")
			var msg = JSON.parse(body);
			
			console.log(msg);
		})
	});

	httpRequest.end();
	
	// polling frequency in milliseconds
	setTimeout(receive, 2000);
}

var p = function(output) {
	console.log(output);
}

receive();