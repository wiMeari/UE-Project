using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UnrealSharp.Attributes;
using UnrealSharp.Engine;

namespace ManagedTeamProject.Controller
{
    [UClass]
    public class ACSPlayerController : APlayerController
    {
        [UProperty(PropertyFlags.EditAnywhere)] public ACSCameraController CameraController { get; set; }

        protected override void BeginPlay()
        {
            base.BeginPlay();
        }

        public override void Tick(float deltaSeconds)
        {
            base.Tick(deltaSeconds);
        }
    }
}
