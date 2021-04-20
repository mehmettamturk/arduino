'use strict';

// const {
//   EtherPortClient
// } = require('etherport-client');
// const { Board, Servo } = require('johnny-five');
// const board = new Board({
//   port: new EtherPortClient({
//     host: '192.168.1.112',
//     port: 3030
//   }),
//   repl: false
// });
var Blynk = require('blynk-library');
var five = require("johnny-five");
var EventEmitter = require('events').EventEmitter;

var board = new five.Board();                   // Objet permettant l'appel à l'API J5 - Object to call J5 API
var AUTH = 'mzfUTrUdACw3uydG_JrRwvsjSkEHCTfY';  // Remplacer par votre Token Blynk - Replace by your Blynk Token

var event = new EventEmitter();                 // Evenements javascript - Javascript Events
var DEBUG = true; //false;                      // Active les messages de mise au point - Activate debug message

// Setup Blynk
var blynk = new Blynk.Blynk(AUTH, {
  // Connecteur au serveur Blynk local - Local Blynk server connector
  connector : new Blynk.TcpClient({ addr:"192.168.1.112", port:3030 } )
});
// var V0 = new blynk.VirtualPin(0);  // Pan servo           
// var V1 = new blynk.VirtualPin(1);  // Tilt servo
// var V2 = new blynk.VirtualPin(2);  // Reset position

blynk.on('connect', function() { console.log("Blynk ready."); });
blynk.on('disconnect', function() { console.log("DISCONNECT"); });

board.on("ready", function() {
  // code
  console.log("J5 Board is Ready");

  var servo = new five.Servo({
    pin: 5,
    startAt: 20
  });
  
  // Set horn to 90 degrees
  servo.to(90);
  
  // Return to startAt value of 20 degrees
  servo.home();


})