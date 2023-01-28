FROM mcr.microsoft.com/dotnet/aspnet:6.0 AS base
WORKDIR /app
EXPOSE 80
EXPOSE 443

FROM mcr.microsoft.com/dotnet/sdk:6.0 AS build
WORKDIR /src
COPY ["Organic-master.csproj", "./"]
RUN dotnet restore "Organic-master.csproj"
COPY . .
WORKDIR "/src/"
RUN dotnet build "Organic-master.csproj" -c Release -o /app/build

FROM build AS publish
RUN dotnet publish "Organic-master.csproj" -c Release -o /app/publish

FROM base AS final
WORKDIR /app
COPY --from=publish /app/publish .
ENTRYPOINT ["dotnet", "Organic-master.dll"]
