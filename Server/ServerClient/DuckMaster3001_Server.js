var http = require('http');
var url = require('url');
var msgLog = [];
var port = 8000;

var p = function(output) {
	console.log(output);
} 

var derpFunc = function(request, response) {
	var pathname = url.parse(request.url).pathname;
	
	if(pathname == "/duckmaster3001_raspberry") {
		
		if(request.method == "POST") {	
			var body = "";
			
			// Receive part of the data
			request.on("data", function(data) {
				p("data");
				body += data;
			})
			
			// Done receiving data, now saving
			request.on("end", function() {
				var msg = JSON.parse(body);
				p("end");
				// do stuff with data
				msgLog.push(msg);
				
				// responses that all went well
				response.writeHeader(200, {"Content-Type": "text/plain"});
				console.log(msg);
			})
		}
	}
	else if(pathname == "/duckmaster3001_application") {
		
		if(request.method == "GET") {	
			var sendData;
			
			if(msgLog.length == 0) {
				sendData = {msg: "Nothing New"};
			}
			else {
				sendData = msgLog.shift();
			}
			
			response.writeHeader(200, {"Content-Type": "application/json"});
			response.write(JSON.stringify(sendData));
		}
	}
	
	response.end();
}

http.createServer(derpFunc).listen(port);

