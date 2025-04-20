
#note to run you have to be in the BotServer folder for it to run if not it wont find path when bulding it 

# Install()

pip install Flask
pip install -U flask-cors
npm install --save-dev style-loader css-loader
npm install react-bootstrap bootstrap

npm install chart.js react-chartjs-2

npm i better version npm i -g npm
pip install boto3
npm install @mui/icons-material // only revalant for FollowBot controller

# Build

npm run build

# Run V

npm run start

In the browser use url: http://xx.xx.xx.xx:5000

where xx.xx.xx.xx is shown in the server command window

# Develop

Two cmd windows:

- First window (for javascript browser development):

`npm run watch` // this command is not working does not allow me to see change as i go 

- Second window (for python server development):

`npm run startdebug` 

In the browser use url: http://localhost:3000/

When finished adding changes please run clean:

`npm run clean`



# fast way  to debug web 

npm run build
npm run start


