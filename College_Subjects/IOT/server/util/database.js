const mysql = require("mysql2");
const mysqlaync = require("mysql2/promise")
var connectDB = mysql.createConnection({
    host     : 'localhost',
    user     : 'root',
    password : 'varunbhojane@07',
    database : 'IOT',
    port:3377
}); 


const getAsyncConnection = async ()=>{
    var asyncConnection = await mysqlaync.createConnection({
        host     : 'localhost',
        user     : 'root',
        password : 'varunbhojane@07',
        database : 'IOT',
        port:3377
    })
    return asyncConnection;
}



module.exports = {connectDB,getAsyncConnection};
