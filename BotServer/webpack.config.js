"use strict";
const CopyPlugin = require("copy-webpack-plugin");
const BrowserSyncPlugin = require('browser-sync-webpack-plugin')

module.exports = {
  mode: 'development',

  entry: './src/index.jsx',
  resolve: {
    extensions: ['.js', '.jsx'],
  },
  output: {
    filename: "main.min.js"
  },

  devtool: 'source-map',

  module: {
    rules: [
      {
        // Javascript
        test: /\.(js|jsx)$/,
        exclude: /(node_modules)/,
        use: {
          loader: 'babel-loader',
          options: {
            presets: ['@babel/preset-env', '@babel/preset-react'],
            plugins: [
              [
                "styled-components",
                {
                  "ssr": true,
                  "displayName": true,
                  "preprocess": false
                }
              ]
            ]
          }
        }
      },
      {
        // images
        test: /\.(png|svg|jpg|jpeg|gif)$/i,
        loader: 'file-loader',
        options: {
          name: 'images/[name].[ext]'
        },
      }
    ]
  },

  plugins: [
    new CopyPlugin({
      patterns: [
        { from: 'index.html', to: '.' },
        { from: 'crazyface.png', to: './images' },
        { from: 'server/*', to: '[name][ext]' },
      ],
    }),
    new BrowserSyncPlugin({
      serveStatic: ['dist'],
      proxy: 'http://127.0.0.1:5000/',
      open: false,
    }),
  ],
};