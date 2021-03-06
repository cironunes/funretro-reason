// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var Util$ReactHooksTemplate = require("./Util.bs.js");
var Comments$ReactHooksTemplate = require("./Comments.bs.js");

function Card(Props) {
  var id = Props.id;
  var text = Props.text;
  var votes = Props.votes;
  var comments = Props.comments;
  return React.createElement("div", {
              id: id
            }, React.createElement("span", undefined, Util$ReactHooksTemplate.ste(text)), votes !== undefined ? React.createElement("div", undefined, Util$ReactHooksTemplate.ste("Votes:"), Util$ReactHooksTemplate.ste(String(votes.length))) : Util$ReactHooksTemplate.ste("0"), React.createElement(Comments$ReactHooksTemplate.make, {
                  comments: comments
                }));
}

var make = Card;

exports.make = make;
/* react Not a pure module */
