// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var React = require("react");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var Util$ReactHooksTemplate = require("./Util.bs.js");
var Comment$ReactHooksTemplate = require("./Comment.bs.js");

function Comments(Props) {
  var comments = Props.comments;
  if (comments !== undefined) {
    return React.createElement("div", undefined, React.createElement("h3", undefined, Util$ReactHooksTemplate.ste("Comments")), React.createElement("div", undefined, $$Array.map((function (comment) {
                          if (comment !== undefined) {
                            var comment$1 = Caml_option.valFromOption(comment);
                            return React.createElement(Comment$ReactHooksTemplate.make, {
                                        id: comment$1.id,
                                        text: comment$1.text,
                                        author: comment$1.author,
                                        key: comment$1.id
                                      });
                          } else {
                            return Util$ReactHooksTemplate.ste("None");
                          }
                        }), comments)));
  } else {
    return Util$ReactHooksTemplate.ste("No comments");
  }
}

var make = Comments;

exports.make = make;
/* react Not a pure module */
