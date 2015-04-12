var http = require('http');
var url = requre('url');
var msgLog = [];
var port = 8000;

http.createServer(derpFunc).listen(port);

var derpFunc = function(request, response) {
	var pathname = url.parse(request.url).pathname;
	
	if(pathname == "/duckmaster3001_raspberry") {
		if(request.method == "POST") {
			var body = "";
			
			// Receive data bit
			request.on("data", function(data)) {
				body += data;
			}
			
			// Done receiving data, now saving
			request.on("end", function()) {
				var msg = JSON.parse(body);
				
				// do stuff with data
				msgLog.push(msg);
				
				console.log(msg);
			}
			
			// responses that all went well
			response.writeHeader(200, {"Content-Type": "text/plain"});
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
			response.write(json.stingify(sendData));
		}
	}
	
	response.end();
}