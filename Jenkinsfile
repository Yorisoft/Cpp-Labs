#!/usr/bin/env groovy

node {
    if(env.BRANCH_NAME.startsWith('PR')){
        return;
    }

    def image
    try{
        stage('Cleanup and Checkout') {
            sh ("echo Branch_name:${env.BRANCH_NAME}");
            cleanWs();
            checkout([
                $class: 'GitSCM',
                branches: [[name: "${env.BRANCH_NAME}"]],
                doGenerateSubmoduleConfigurations: false, 
                extensions: [], 
                submoduleCfg: [], 
                userRemoteConfigs: [[credentialsId: 'Yorisoft', url: 'https://github.com/Yorisoft/cpp-labs' ]]
            ])
        }

        stage('Build Image') {
            image = docker.build('cpp-labs');
        }

        stage('Building BankAccounts') {
            image.inside("--entrypoint=''") {
                sh ("chmod +x 284/Group_Project/BankAccounts/scripts/linux-build.sh");
                sh ('284/Group_Project/BankAccounts/scripts/linux-build.sh');
                echo ('Done building project files.. ');
            } 
        } 

        stage('Running BankAccounts') {
            image.inside("--entrypoint=''") {
                sh ("chmod +x 284/Group_Project/BankAccounts/scripts/linux-run.sh");
                sh ('284/Group_Project/BankAccounts/scripts/linux-run.sh');
                echo ('Done building project files.. ');
            } 
        }

        stage('Testing BankAccounts') {
            image.inside("--entrypoint=''") {
                sh ('1000.00');
                sh ('1000.00');
                sh ('0.50');
                sh ('1');
                sh ('152.50');
                sh ('y');
                sh ('1');
                sh ('152.50');
                sh ('y');
                sh ('5');
                sh ('1');
                sh ('n');
                echo ('Done building project files.. ');
            } 
        }
    }
        
    catch (e) {
        currentBuild.result = 'FAILURE';
        throw e
    } 
    finally {
        stage('Create Archive'){
            archiveArtifacts allowEmptyArchive: true, artifacts: 'bin/Debug/*', fingerprint: true; 
            //archiveArtifacts allowEmptyArchive: true, artifacts: 'record/screen_shots/newegg/*.png, record/screen_shots/bestbuy/*.png, record/screen_shots/target/*.png'; 
        }
        
        stage('cleanup'){
            cleanWs();
            sh('docker system prune -a -f');
        }
    }
} 
