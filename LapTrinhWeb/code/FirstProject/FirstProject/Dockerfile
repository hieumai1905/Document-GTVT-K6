FROM mcr.microsoft.com/dotnet/aspnet:6.0 AS base
WORKDIR /app
EXPOSE 80
EXPOSE 443

FROM mcr.microsoft.com/dotnet/sdk:6.0 AS build
WORKDIR /src
COPY ["FirstProject/FirstProject.csproj", "FirstProject/"]
RUN dotnet restore "FirstProject/FirstProject.csproj"
COPY . .
WORKDIR "/src/FirstProject"
RUN dotnet build "FirstProject.csproj" -c Release -o /app/build

FROM build AS publish
RUN dotnet publish "FirstProject.csproj" -c Release -o /app/publish

FROM base AS final
WORKDIR /app
COPY --from=publish /app/publish .
ENTRYPOINT ["dotnet", "FirstProject.dll"]
