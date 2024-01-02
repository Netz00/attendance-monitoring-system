 [Source](https://github.com/esp8266/Arduino/blob/master/libraries/ESP8266WiFi/examples/BearSSL_ServerClientCert/BearSSL_ServerClientCert.ino)
 
 
 To run this example:
  1. Generate a private certificate-authority certificate and key:
        ```shell
        openssl genrsa -out ca_key.pem 2048
        openssl req -x509 -new -nodes -key ca_key.pem -days 4096 -config ca.conf -out ca_cer.pem
        ```

  2. Generate a private server certificate and key pair
        ```shell
        openssl genrsa -out server_key.pem 2048
        openssl req -out server_req.csr -key server_key.pem -new -config server.conf
        openssl x509 -req -in server_req.csr -out server_cer.pem -sha256 -CAcreateserial -days 4000 -CA ca_cer.pem -CAkey ca_key.pem
        ```

  3. Generate any number of private client certificate/key pairs (using the private CA above)

        ```shell
        openssl genrsa -out client1_key.pem 2048
        openssl req -out client1_req.csr -key client1_key.pem -new -config client.conf
        openssl x509 -req -in client1_req.csr -out client1_cer.pem -sha256 -CAcreateserial -days 4000 -CA ca_cer.pem -CAkey ca_key.pem
        ```

 

