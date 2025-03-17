<h1> AWS Database Communications</h1>

<h3> Local AWS Database Set-up </h3>

1. Add or uncomment`endpoint_url = "http://localhost:<port>"` at `/db_server/db_resource`.
2. Download the zip file `DynamoDBLocal.jar` from [AWS Documentation](https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/DynamoDBLocal.DownloadingAndRunning.html).
3. Install [AWS CLI](https://docs.aws.amazon.com/cli/latest/userguide/getting-started-install.html)
4. In terminal, configure with the command `aws configure` to match `server/db_server/settings.py`. Set default output format to `json`.
5. In terminal, cd to where `DynamoDBLocal.jar` is saved i.e. `cd ./dynamodb_local_latest`.
6. Run the local db with the command: `java -D"java.library.path=./DynamoDBLocal_lib" -jar DynamoDBLocal.jar`.
   * Default port is 8000. If it needs to be changed run this command `java -D"java.library.path=./DynamoDBLocal_lib" -jar DynamoDBLocal.jar -port <port-no.>` and change `/db_server/db_resource.py` to match ports.
7. Useful commands:
   * `aws dynamodb list-tables --endpoint-url http://localhost:8000`
   * `aws dynamodb scan --table-name <TableName> --endpoint-url http://localhost:8000`
   * `aws dynamodb delete-item --table-name Users --key '{"PrimaryKey": {"S":"PrimaryKeyValue"}}' --endpoint-url http://localhost:8000`
   * `aws dynamodb put-item --table-name FollowBots --item '{"bot_id": {"S": "123"},"functional_key": {"S": "xyz"},"logs": {"L": []},"business_id": {"S": "001"},"assigned_user_id": {"NULL": true}}' --endpoint-url http://localhost:8000`

<h3> Arduino Client Database Interactions </h3>

On the very first boot-up, the Arduino client will send a persistent functional-key produced by the robotic interface.
* After successful call to `/api/createBotEntry`, the server will return `JSON` with the field `botId` that corresponds to the FollowBot entry in the database. 
* It is expected that the Arduino client keeps track of `IN_DATABASE` and updates the variable after a successful call to avoid repeated entries.
* It is expected that the Arduino client keeps track of the returned `DATABASE_ID` and includes this is in all `JSON` requests under `botId` i.e.,
`{
    “botId”: DATABASE_ID,
    "temperature": 55,
    "lastKnownLocation": {
      "latitude": x,
      "longitude": y
    },
    "battery": 78,
    "time": "14:32:15",
    "date": "2025-03-10"
  }
`

<h3> Website Client Database Interactions </h3>

* Webpages meant to interact with a specific FollowBot should include the `botId` with the API calls.
1. The URLs should include this `botId` via including the colon prefix i.e. `<Route path="/bot-analytics/:botId" element={<Layout><BotAnalyticsPage /></Layout>} />`
2. In JavaScript, the statement `const { botId } = useParams();` will be able to extract the `botId` from the URL.
3. Subsequent API calls from this webpage should be made using this `botId` i.e. `/api/getBotLogs?bot_id=${botId}`, `/api/postTargetCoords?bot_id=${botId}`

* For interacting with User entries, the command `user_id = flask_login.current_user.id` can be used within `server.py` to retrieve the `user_id` needed to access user data of the session user.
