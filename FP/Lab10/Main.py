from Repository import Repo
from Service import Service
from UI import Presentation

repo = Repo()
service = Service(repo)
ui = Presentation(service)
ui.start()
