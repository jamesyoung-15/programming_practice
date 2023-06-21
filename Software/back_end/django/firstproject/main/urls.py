from django.urls import path

from . import views

urlpatterns = [
    path("", views.hellworld, name="helloworld"),
    path("<int:id>",views.index, name="index"),
    path("v1",views.v1, name="v1"),
    path('create/', views.create, name="create"),
]