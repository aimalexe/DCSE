from flask import Flask

helloworld = Flask(__name__)

@helloworld.route("/")
def run():
    return "{\"message\":\"Hello World from aimalexe Python v0.0.2\"}"

if __name__ == "__main__":
    helloworld.run(host="0.0.0.0", port=int("5000"), debug=True)