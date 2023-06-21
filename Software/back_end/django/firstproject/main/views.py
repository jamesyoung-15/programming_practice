from django.shortcuts import render
from django.http import HttpResponse, HttpResponseRedirect
from .models import ToDoList, Item
from .forms import CreateNewList
# Create your views here.

def hellworld(response):
    return render(response, "main/base.html",{})

def index(response, id):
    ls = ToDoList.objects.get(id=id)
    return render(response, "main/index.html", {"ls": ls})

def v1(response):
    return HttpResponse("View 1")

def create(response):
    if response.method == "POST":
        # Create form and pass dictionary with values
        form = CreateNewList(response.POST)

        # create new list
        if form.is_valid():
            n = form.cleaned_data["name"]
            t  = ToDoList(name = n)
            t.save()

        return HttpResponseRedirect("/%i" %t.id)
    else:
        form = CreateNewList()
    return render(response, "main/create.html",{"form": form})