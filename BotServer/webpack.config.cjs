"use strict";
const CopyPlugin = require("copy-webpack-plugin");
const BrowserSyncPlugin = require('browser-sync-webpack-plugin');
const { CleanWebpackPlugin } = require('clean-webpack-plugin');
const path = require('path');

module.exports = {
  mode: 'development',

  entry: './src/index.jsx',
  resolve: {
    extensions: ['.js', '.jsx'],
  },
  output: {
    filename: "main.min.js",
    path: path.resolve(__dirname, 'dist'),
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
        test: /\.css$/,
        use: ["style-loader", "css-loader"],
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
    new CleanWebpackPlugin(),
    new CopyPlugin({
      patterns: [
        { from: 'public/index.html', to: '.' },
        { from: 'public/logo.png', to: 'images' },
        { from: 'server/*', to: 'server/[name][ext]' },
        { from: 'server/db_server/*', to: 'server/db_server/[name][ext]'},
        { from: 'fonts/*', to: 'fonts/[name][ext]'},
      ],
    }),
    new BrowserSyncPlugin({
      files: ['dist/**/*'],
      proxy: 'http://127.0.0.1:5000/',
      open: false,
    }),
  ],
};