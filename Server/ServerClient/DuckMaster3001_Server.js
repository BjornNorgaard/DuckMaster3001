var http = require('http');
var url = require('url');
var msgLog = [];
var port = 8000;

var derpFunc = function(request, response) {
	
	p("In derpFunc");
	
	var pathname = url.parse(request.url).pathname;
	
	p("pathname");
	
	if(pathname == "/duckmaster3001_raspberry") {
		if(request.method == "POST") {	

			p("pn = rasb");	
			
			var body = "";
			//p("in request")
			// Receive data bit
			request.on("data", function(data) {
				p("request.on: data");	
				body += data;
			})
			
			// Done receiving data, now saving
			request.on("end", function() {
				
				p("request.on: end");	
				
				var msg = JSON.parse(body);
				
				// do stuff with data
				msgLog.push(msg);
				
				// responses that all went well
				response.writeHeader(200, {"Content-Type": "text/plain"});
				
				console.log(msg);
			})
			
			
			
			p("exiting rasb if");
		}
	}
	else if(pathname == "/duckmaster3001_application") {
		
		p("entering if app");
		
		if(request.method == "GET") {	

			p("in req method");
			var sendData;
			
			if(msgLog.length == 0) {
				p("msglog Lenght");
				sendData = {msg: "Nothing New"};
			}
			else {
				p("lenght other than 0");
				sendData = msgLog.shift();
			}
			
			response.writeHeader(200, {"Content-Type": "application/json"});
			response.write(JSON.stingify(sendData));
		}
		
		p("done with app");
	}
	
	response.end();
}

var p = function(output) {
	console.log(output);
}

http.createServer(derpFunc).listen(port);

