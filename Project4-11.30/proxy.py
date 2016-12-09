import tornado.ioloop
import tornado.web
import os


class MainHandler(tornado.web.RequestHandler):

    def get(self):
        self.render("./index.html")


if __name__ == "__main__":
    settings = {
        "static_path": os.path.join(os.path.dirname(__file__), "static")
    }
    application = tornado.web.Application([
        (r"/", MainHandler), settings
    ])
    print "listening on 8888"
    http_server = tornado.httpserver.HTTPServer(application)
    http_server.listen(8888)
    tornado.ioloop.IOLoop.instance().start()
