// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var ReactApollo = require("react-apollo");
var App$ReactHooksTemplate = require("./App.bs.js");
var Client$ReactHooksTemplate = require("./Client.bs.js");

ReactDOMRe.renderToElementWithId(React.createElement(ReactApollo.ApolloProvider, {
          client: Client$ReactHooksTemplate.instance,
          children: React.createElement(App$ReactHooksTemplate.make, { })
        }), "app");

/*  Not a pure module */
