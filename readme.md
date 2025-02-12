# Simple HTTP-like Server in C

This project is a basic TCP server written in C that listens on port **8181** and responds with a simple message when a client connects. The server is tested on a **Linux** system using **Telnet** and network commands like `netstat`.

## How It Works

- The server creates a **TCP socket** and binds it to **port 8181**.
- It listens for incoming connections.
- When a client connects, it reads incoming data.
- The server responds with a simple message: `httpd v1.3`.
- The connection is then closed.

## Compilation & Execution

To compile the code, use:

```bash
gcc -o server server.c
```

Run the server:

```bash
./server
```

## Testing the Server

### **Check Listening Ports**

Before connecting, verify that the server is listening on port **8181**:

```bash
netstat -an | grep LISTEN
```

#### Explanation:

- `netstat -an` → Displays active network connections and listening ports.
- `grep LISTEN` → Filters output to show only listening ports.

### **Connecting to the Server**

Use **Telnet** to test the connection:

```bash
env - telnet localhost 8181
```

#### Explanation:

- `env - telnet localhost 8181` → Runs `telnet localhost 8181` in an environment-modified shell.
- If successful, the server responds with `httpd v1.3`.

## Notes

- This server runs on **Linux**.
- The server responds only once per connection and then closes.
- Modify the response in `data` for custom messages.

## Disclaimer

This project is for learning purposes only and is **not a fully functional HTTP server**.

