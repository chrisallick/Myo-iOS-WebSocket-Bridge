Myo-iOS-WebSocket-Bridge
========================

This will take all your Myo readings and pass them along as JSON via a WebSocket connection.

I wrote this in an hour so if you have any questions, let me know and i'll update the code/address them.

You need to run the javascript demo on a webserver, on OSX this is very simple:

open up the terminal.

cd to the javascript demo folder with index.html in it.

$> cd /some_path/javascript_demo/myo_js

and then run:

$> python -m SimpleHTTPServer

navigate to:

http://localhost:8000


Now, this assumes you have a local websocket server running on:

localhost:8882

If you don't, navigate to my repository and download RubyWSJSON, that is what im using.

Here are some videos of it working:



