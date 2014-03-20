// var tag = document.createElement('script');

// tag.src = "https://www.youtube.com/iframe_api";
// var firstScriptTag = document.getElementsByTagName('script')[0];
// firstScriptTag.parentNode.insertBefore(tag, firstScriptTag);

function onYouTubeIframeAPIReady() {
    player = new YT.Player('player', {
        height: '390',
        width: '640',
        videoId: 'M7lc1UVf-VE',
        events: {
            'onReady': onPlayerReady,
            'onStateChange': onPlayerStateChange
        }
    });
}

function onPlayerReady(event) {
    //event.target.playVideo();
}
      
function onPlayerStateChange(event) {
    if (event.data == YT.PlayerState.PLAYING && !done) {
        setTimeout(stopVideo, 6000);
        done = true;
    }
}
function stopVideo() {
    player.stopVideo();
}

var kraken;
var player;
var done = false;
var player;
var playing = false;
$(document).ready(function() {

    kraken = new KrakenJS( window, {
        username: "receiver",
        roomname: "myo_armband",
        host: "localhost",
        //host: "localhost",
        port: "8882",
        secure: false,
        debug: false
    });

    /*
        register events, it'll validate the data type
    */

    // true to get raw message
    kraken.addEvent("accel","object",true,function(msg){
        //console.log( msg );
        data.acceleration.x = msg.x,
        data.acceleration.y = msg.y,
        data.acceleration.z = msg.z
    });

    kraken.addEvent("pose","string",false,function(msg){
        //console.log( msg );
        if( msg == "fingers_spread" ) {
            if( !playing ) {
                playing = true;    
                player.playVideo();
            }
        } else if( msg == "wave_out" ) {
            if( playing ) {
                playing = false;
                player.pauseVideo();
            }
        }
    });

    kraken.connect();

      function onYouTubeIframeAPIReady() {
        console.log("asdf");
        player = new YT.Player('player', {
          height: '390',
          width: '640',
          videoId: 'M7lc1UVf-VE',
          events: {
            'onReady': onPlayerReady,
            'onStateChange': onPlayerStateChange
          }
        });
      }

      // 4. The API will call this function when the video player is ready.
      function onPlayerReady(event) {
        //event.target.playVideo();
        player.playVideo();
      }

      // 5. The API calls this function when the player's state changes.
      //    The function indicates that when playing a video (state=1),
      //    the player should play for six seconds and then stop.
      var done = false;
      function onPlayerStateChange(event) {
        if (event.data == YT.PlayerState.PLAYING && !done) {
          setTimeout(stopVideo, 6000);
          done = true;
        }
      }
      function stopVideo() {
        player.stopVideo();
      }
});